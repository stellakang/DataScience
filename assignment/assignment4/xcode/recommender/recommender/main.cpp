#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <unordered_map>
#include <queue>

using namespace std;

#define ll long long
#define um unordered_map

struct record{
    int user, item;
    double rating;
};

class Recommender{
private:
    int topN;
    int numOfUsers,numOfItems;
    um<int,int> itemToIndx;
    um<int,int> userToIndx;

    vector<vector<double>>ratings;
    vector<vector<double>>userSimilarity;
    vector<vector<double>>itemSimilarity;
    vector<double>average;
public:
    Recommender(int _topN, um<int,int> _itemToIndx, um<int,int> _userToIndx,
                vector<vector<double>> _matrix){
        topN = _topN;
        numOfUsers = int(_userToIndx.size());
        numOfItems = int(_itemToIndx.size());
        itemToIndx = _itemToIndx;
        userToIndx = _userToIndx;
        //cout<<"The number of users : "<<numOfUsers<<endl;
        //cout<<"The number of items : "<<numOfItems<<endl;
        ratings = _matrix;
        
        userSimilarity.resize(numOfUsers+1);
        for(int i=0;i<=numOfUsers;i++)
            userSimilarity[i].resize(numOfUsers+1);
        
        itemSimilarity.resize(numOfItems+1);
        for(int i=0;i<=numOfItems;i++)
            itemSimilarity[i].resize(numOfItems+1);
        
        average.resize(numOfUsers+1);
    }
    vector<record> run(vector<record> testSet){
        training();
        vector<record> result = test(testSet);
        return result;
    }
    void training(){
        trainCF();
    }
    vector<record> test(vector<record> testSet){
        for(int i=0;i<testSet.size();i++){
            double ratingOfCF=predictUserBasedCF(testSet[i].user,testSet[i].item);
            //cout<<"before : "<<testSet[i].rating<<", ";
            testSet[i].rating = ratingOfCF;
            //cout<<"after : "<<testSet[i].rating<<endl;
        }
        return testSet;
    }
    void trainCF(){
        calculateAverage();
        calculateUserBasedCosine();
    }
    void calculateAverage(){
        for(int i=1;i<=numOfUsers;i++){
            double sum=0.0;
            int cnt=0;
            for(double r: ratings[i]){
                if(r==-1.0)continue;
                sum+=r;
                cnt++;
            }
            average[i]=sum/(double)cnt;
        }
    }
    void calculateUserBasedCosine(){
        //cosine 유사도
        for(int u1=1;u1<=numOfUsers;u1++){
            for(int u2=u1+1;u2<=numOfUsers;u2++){
                double top=0.0,bottomLeft=0.0, bottomRight=0.0,val=0.0;
                
                for(int item=1;item<=numOfItems;item++){
                    double u1toitem=ratings[u1][item];
                    double u2toitem=ratings[u2][item];
                    
                    if(u1toitem!=-1.0 && u2toitem!=-1.0){
                        top+=u1toitem*u2toitem;
                        bottomLeft+=u1toitem*u1toitem;
                        bottomRight+=u2toitem*u2toitem;
                    }
                    else if(u1toitem!=-1.0)
                        bottomLeft+=u1toitem*u1toitem;
                    else if(u2toitem!=-1.0)
                        bottomRight+=u2toitem*u2toitem;
                }
                val=top/(sqrt(bottomLeft)*sqrt(bottomRight));
                userSimilarity[u1][u2]=userSimilarity[u2][u1]=val;
                //cout<<"u1 : "<<u1<<" u2 : "<<u2<<" similarity: "<<val<<endl;
            }
        }
    }
    void calculateItemBasedCosine(){
        //cosine 유사도
        for(int i1=1;i1<=numOfItems;i1++){
            for(int i2=i1+1;i2<=numOfItems;i2++){
                double top=0.0,bottomLeft=0.0, bottomRight=0.0,val=0.0;
                
                for(int user=1;user<=numOfUsers;user++){
                    double usertoi1=ratings[user][i1];
                    double usertoi2=ratings[user][i2];
                    if(usertoi1!=-1.0 && usertoi2!=-1.0){
                        top+=usertoi1*usertoi2;
                        bottomLeft+=usertoi1*usertoi1;
                        bottomRight+=usertoi2*usertoi2;
                    }
                    else if(usertoi1!=-1.0)
                        bottomLeft+=usertoi1*usertoi1;
                    else if(usertoi2!=-1.0)
                        bottomRight+=usertoi2*usertoi2;
                }
                if(bottomLeft*bottomRight!=0.0)
                    val=top/(sqrt(bottomLeft)*sqrt(bottomRight));
                itemSimilarity[i1][i2]=itemSimilarity[i2][i1]=val;
                //cout<<"u1 : "<<i1<<" u2 : "<<i2<<" similarity: "<<val<<endl;
            }
        }
    }
    void calculatePCC(){
        //모든 페어간의 유사도 구하기
        for(int u1=1;u1<=numOfUsers;u1++){
            for(int u2=u1+1;u2<=numOfUsers;u2++){
                double top=0.0,bottomLeft=0.0, bottomRight=0.0,val=0.0;
                
                for(int item=1;item<=numOfItems;item++){
                    if(ratings[u1][item]==-1.0 || ratings[u2][item]==-1.0)continue;
                    
                    double u1toitem=ratings[u1][item]-average[u1];
                    double u2toitem=ratings[u2][item]-average[u2];
                    
                    top+=u1toitem*u2toitem;
                    bottomLeft+=u1toitem*u1toitem;
                    bottomRight+=u2toitem*u2toitem;
                }
                if(bottomLeft*bottomRight!=0)
                    val=top/sqrt(bottomLeft*bottomRight);
                else// pcc 가 정의되지 않는 경우 = 공통 부분이 없는 경우
                    val=0.0;
                userSimilarity[u1][u2]=userSimilarity[u2][u1]=val;
            }
        }
    }
    double predictItemBasedCF(int user, int item){
        if(userToIndx[user]==0)
            return 3.0;
        
        if(itemToIndx[item]==0)
            return average[user];
        
        //collaborative filtering
        double sum=0.0;
        double similaritySum=0.0;
        
        user=userToIndx[user];
        item=itemToIndx[item];
        
        priority_queue<pair<double,int>>topNeighbors;
        for(int neighbor=1;neighbor<=numOfItems;neighbor++){
            if(item==neighbor)continue;
            if(ratings[user][neighbor]==-1.0)continue;
            topNeighbors.push(make_pair(-itemSimilarity[item][neighbor],neighbor));
            while(topNeighbors.size()>topN)
                topNeighbors.pop();
        }
        
        while(!topNeighbors.empty()){
            int neighbor=topNeighbors.top().second;
            topNeighbors.pop();
            sum+=itemSimilarity[item][neighbor]*(ratings[user][neighbor]);
            similaritySum+=abs(itemSimilarity[item][neighbor]);
        }
        
        //double score=sum/similaritySum;
        double score=sum/(similaritySum);
        return score;
    }
    double predictUserBasedCF(int user, int item){
        if(userToIndx[user]==0)
            return 2.5;
        
        if(itemToIndx[item]==0)
            return average[user];
        
        //collaborative filtering
        double sum=0.0;
        double similaritySum=0.0;
        
        user=userToIndx[user];
        item=itemToIndx[item];
        
        priority_queue<pair<double,int>>topNeighbors;
        for(int neighbor=1;neighbor<=numOfUsers;neighbor++){
            if(user==neighbor)continue;
            if(ratings[neighbor][item]==-1.0)continue;
            topNeighbors.push(make_pair(-userSimilarity[user][neighbor],neighbor));
            while(topNeighbors.size()>topN)
                topNeighbors.pop();
        }
        
        while(!topNeighbors.empty()){
            int neighbor=topNeighbors.top().second;
            topNeighbors.pop();
            sum+=userSimilarity[user][neighbor]*(ratings[neighbor][item]-average[neighbor]);
            //sum+=userSimilarity[user][neighbor]*ratings[neighbor][item];
            similaritySum+=abs(userSimilarity[user][neighbor]);
        }
        //double score=sum/similaritySum;
        double score=average[user]+sum/(similaritySum+0.7);
        return score;
    }
};

class Mapping{
private:
    um<int,int> userToIndx;
    um<int,int> itemToIndx;
    vector<vector<double>>mat;
public:
    um<int,int> getUserToIndx(vector<record> trainSet){
        int numOfUsers=0;

        for(record r: trainSet){
            if(userToIndx[r.user]==0)
                userToIndx[r.user]=++numOfUsers;
        }
        return userToIndx;
    }
    um<int,int> getItemToIndx(vector<record> trainSet){
        int numOfItems=0;

        for(record r: trainSet){
            if(itemToIndx[r.item]==0)
                itemToIndx[r.item]=++numOfItems;
        }
        return itemToIndx;
    }
    vector<vector<double>> generateMatrix(vector<record> trainSet){
        
        vector<vector<double>>mat;
        
        if(userToIndx.empty())
            userToIndx=getUserToIndx(trainSet);
        if(itemToIndx.empty())
            itemToIndx=getItemToIndx(trainSet);
        
        int numOfUsers=int(userToIndx.size())+1;
        int numOfItems=int(itemToIndx.size())+1;
        
        mat.resize(numOfUsers);
        for(int i=0;i<numOfUsers;i++)
            mat[i].resize(numOfItems,-1.0);
        
        for(record r: trainSet){
            int user=userToIndx[r.user];
            int item=itemToIndx[r.item];
            mat[user][item]=r.rating;
        }
        
        return mat;
    }
};

class IO{
private:
    ifstream readFile;
    ofstream writeFile;
    vector<record>trainSet;
    vector<record>testSet;
public:
    void trainfileRead(string trainFile){
        readFile.open(trainFile);
        if(readFile.is_open()) {
            string s;
            while(getline(readFile, s))
                trainSet.push_back(split(s,'\t'));
            readFile.close();
        }
        else{
            cout << "Train file is not opened\n";
            exit(0);
        }
    }
    void testfileRead(string testFile){
        readFile.open(testFile);
        if(readFile.is_open()) {
            string s;
            while(getline(readFile, s))
                testSet.push_back(split(s,'\t'));
            readFile.close();
        }
        else{
            cout << "Test file is not opened\n";
            exit(0);
        }
    }
    void createOutputFile(string trainFile, vector<record>result){
        writeFile.open(trainFile+"_prediction.txt");

        if(writeFile.is_open()) {
            for(record r: result){
                writeFile<<r.user<<'\t';
                writeFile<<r.item<<'\t';
                writeFile<<r.rating<<'\n';
            }
            writeFile.close();
        }
        else{
            cout << "Ouput file is not opened\n";
            exit(0);
        }
    }
    record split(string str, char delimiter) {
        record tmp;
        stringstream ss(str);
        string temp;
        getline(ss,temp,delimiter);
        tmp.user=stoi(temp);
        getline(ss,temp,delimiter);
        tmp.item=stod(temp);
        getline(ss,temp,delimiter);
        tmp.rating=stod(temp);
        return tmp;
    }
    
    vector<record>getTrainSet(){
        return trainSet;
    }
    vector<record>getTestSet(){
        return testSet;
    }
};

int main(int argc, const char * argv[]) {
    
    string trainFile = argv[1]; //train file name ex. u1.base
    string testFile = argv[2]; //test file name ex. u1.test
    
    IO ioclass;
    ioclass.trainfileRead(trainFile);
    ioclass.testfileRead(testFile);
    
    Mapping mapping;
    vector<record>trainSet=ioclass.getTrainSet();
    um<int,int> userToIndx=mapping.getUserToIndx(trainSet);
    um<int,int> itemToIndx=mapping.getItemToIndx(trainSet);
    vector<vector<double>> matrix=mapping.generateMatrix(trainSet);
    
    int topN=35;
    //int topN=15;
    Recommender reco(topN, itemToIndx, userToIndx, matrix);
    vector<record> result=reco.run(ioclass.getTestSet());
    
    ioclass.createOutputFile(trainFile, result);
    
    return 0;
}
