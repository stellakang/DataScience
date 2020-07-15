#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <set>
#include <string>
#include <sstream>
#include <math.h>
#include <float.h>
using namespace std;
class Node{
private:
    int numOfSamples;
    int numOfAttr;
    vector<vector<string>>tuples;//tuples
    vector<Node>child;//child node
    pair<int,string> nodeAttr;
    vector<bool>attrChecker;
public:
    Node(vector<vector<string>>_tuples, pair<int,string>attrInfo){
        tuples = _tuples;
        nodeAttr = attrInfo;
        numOfSamples=int(tuples.size());
        numOfAttr=int(tuples[0].size()-1);
        attrChecker.resize(numOfAttr,false);
    }
    vector<vector<string>> getTuples(){
        return tuples;
    }
    int getNumOfSamples(){
        return numOfSamples;
    }
    int getNumOfChildren(){
        return int(child.size());
    }
    void setChild(int i,Node childNode){
        child[i]=childNode;
    }
    pair<int,string> getNodeAttr(){
        return nodeAttr;
    }
    vector<Node> getChildren(){
        return child;
    }
    vector<bool> getAttrChecker(){
        return attrChecker;
    }
    void checkAttr(int indx){
        attrChecker[indx]=true;
    }
    void addChild(vector<vector<string>>tuple,pair<int,string>attr){
        child.push_back(Node(tuple,attr));
    }
};

class DecisionTree{
private:
    Node root;
    int numOfAttr;
    int numOfAllSamples;
    double threshold=0.001;
    vector<vector<string>>trainSet;
    vector<vector<string>>testSet;
public:
    DecisionTree(vector<vector<string>> _trainSet, vector<vector<string>> _testSet):
    trainSet(_trainSet), testSet(_testSet), root(_trainSet,make_pair(-1,"")){
        numOfAttr=int(trainSet[0].size()-1);
        numOfAllSamples=int(trainSet.size());
    }
    void run(){
        training();
        test();
    }
    void training(){
        root=partition(root);
    }
    void test(){
        for(int i=0;i<testSet.size();i++){
            string ans=testSamples(testSet[i],root);
            testSet[i].push_back(ans);
        }
    }
    string testSamples(vector<string>sample, Node node){
        if(node.getNumOfChildren()==0){
            int classIndx=int(numOfAttr);
            vector<vector<string>>tuple=node.getTuples();
            map<string,int>m;
            for(auto tup:tuple)
                m[tup[classIndx]]++;
            int numOfTuplesInClass=0;
            string labelName;
            for(pair<string,int>group:m){
                if(group.second>numOfTuplesInClass){
                    numOfTuplesInClass=group.second;
                    labelName=group.first;
                }
            }
            return labelName;
        }
        vector<Node>children=node.getChildren();
        for(auto childNode:children){
            pair<int,string>attrPair=childNode.getNodeAttr();
            if(sample[attrPair.first]==attrPair.second)
                return testSamples(sample, childNode);
        }
        return "None";
    }
    vector<vector<string>>getTestResult(){
        return testSet;
    }
    double getEntropy(vector<vector<string>>tuple){
        map<string,int>m;
        int classIndx=int(numOfAttr);
        double info=0.0;
        for(auto tup:tuple){
            m[tup[classIndx]]++;
        }
        for(pair<string,int> p:m){
            int num=int(p.second);
            double prob=(double)num/(double)tuple.size();
            info-=prob*log2(prob);
        }
        return info;
    }
    double getEntropyAttr(int attrIndx,vector<vector<string>> tuple){
        double infoAttr=0.0;
        map<string,vector<vector<string>>>m;
        for(auto tup:tuple){
            m[tup[attrIndx]].push_back(tup);
        }
        for(auto group:m){
            vector<vector<string>>groupedTuples=group.second;
            infoAttr+=((double)groupedTuples.size()/(double)tuple.size())*getEntropy(groupedTuples);
        }
        return infoAttr;
    }
    double getSplitInfo(int attrIndx, vector<vector<string>> tuple){
        double splitInfo=0.0;
        double numOfTuples=double(tuple.size());
        map<string,int>m;
        for(auto tup:tuple){
            m[tup[attrIndx]]++;
        }
        for(auto group:m){
            double prob=((double)group.second)/numOfTuples;
            splitInfo-=prob*log2(prob);
        }
        return splitInfo;
    }
    int attrSelection(Node node){
        double info=getEntropy(node.getTuples());
        int attrSelected=-1;
        double gainRatioMax=0.0;
        vector<bool>attrChecker=node.getAttrChecker();
        for(int i=0;i<numOfAttr;i++){
            if(attrChecker[i])continue;
            vector<vector<string>>tuples=node.getTuples();
            double gain=info-getEntropyAttr(i,tuples);
            double splitInfo=getSplitInfo(i, tuples);
            if(gain/splitInfo>gainRatioMax){
                attrSelected=i;
                gainRatioMax=gain/splitInfo;
            }
        }
        return attrSelected;
    }
    Node partition(Node node){
        if(isEnd(node)==true)return node;
        int attrIndx=attrSelection(node);
        node.checkAttr(attrIndx);
        map<string,vector<vector<string>>>m;
        for(auto tup:node.getTuples())
            m[tup[attrIndx]].push_back(tup);
        double childAverageSamples=(double)node.getNumOfSamples()/(double)m.size();
        if(childAverageSamples/numOfAllSamples>=threshold){
            for(auto group:m){
                node.addChild(m[group.first],make_pair(attrIndx,group.first));
            }
            vector<Node>child=node.getChildren();
            int num=node.getNumOfChildren();
            for(int i=0;i<num;i++){
                node.setChild(i, partition(child[i]));
            }
        }
        return node;
    }
    bool isEnd(Node node){
        //no samples left
        int numOfSamples=node.getNumOfSamples();
        if(numOfSamples==0)return true;
        //belong to the same class
        int classIndx=int(numOfAttr);
        vector<vector<string>>tuples=node.getTuples();
        map<string,int>m;
        for(auto tup:tuples)
            m[tup[classIndx]]++;
        if(m.size()==1)return true;
        //no remaining attributes
        vector<bool>attrChecker=node.getAttrChecker();
        int num=0;
        for(int i=0;i<numOfAttr;i++){
            if(attrChecker[i]==false)num++;
        }
        if(num==0)return true;
        return false;
    }
};
class IO{
private:
    string trainFile;
    string testFile;
    string resultFile;
    string attrSet;
    ifstream readFile;
    ofstream writeFile;
    vector<vector<string>>trainSet;
    vector<vector<string>>testSet;
public:
    IO(string train, string test, string result){
        trainFile = train;
        testFile = test;
        resultFile = result;
    }
    void fileRead(){
        readFile.open(trainFile);
        if(readFile.is_open()) {
            string s;
            getline(readFile,s);
            attrSet=s;
            while(getline(readFile, s)){
                vector<string> parse = split(s,'\t');
                if(parse.size()>0)
                    trainSet.push_back(parse);
            }
            readFile.close();
        }
        else{
            cout << "Train file is not opened\n";
            exit(0);
        }
        readFile.open(testFile);
        if(readFile.is_open()) {
            string s;
            getline(readFile,s);
            while(getline(readFile, s)){
                vector<string> parse = split(s,'\t');
                if(parse.size()>0)
                    testSet.push_back(parse);
            }
            readFile.close();
        }
        else{
            cout << "Test file is not opened\n";
            exit(0);
        }
    }
    void createOutputFile(vector<vector<string>>testFile){
        writeFile.open(resultFile);
        if(writeFile.is_open()) {
            writeFile<<attrSet;
            for(vector<string> row:testFile){
                for(int i=0;i<row.size();i++){
                    if(i==row.size()-1)
                        writeFile<<row[i];
                    else
                        writeFile<<row[i]<<'\t';
                }
                writeFile<<'\n';
            }
            writeFile.close();
        }
        else{
            cout << "Ouput file is not opened\n";
            exit(0);
        }
    }
    vector<string> split(string str, char delimiter) {
        vector<string> ret;
        string str2=str.erase(str.find_last_not_of("\n"));
        stringstream ss(str2);
        string temp;
        
        while (getline(ss, temp, delimiter))
            ret.push_back(temp);
        
        return ret;
    }
    vector<vector<string>>getTrainSet(){
        return trainSet;
    }
    vector<vector<string>>getTestSet(){
        return testSet;
    }
//    void compareResult(vector<vector<string>>resultSet){
//        int classIndx=int(trainSet[0].size()-1);
//        int num=0;
//        int totalNum=int(resultSet.size());
//        for(int i=0;i<answer.size();i++){
//            if(answer[i][classIndx]==resultSet[i][classIndx])
//                num++;
//        }
//        printf("%d / %d\n",num,totalNum);
//    }
};
int main(int argc, const char * argv[]) {
    string trainFile = argv[1]; //train file name ex. dt_train.txt
    string testFile = argv[2]; //test file name ex. dt_test.txt
    string resultFile = argv[3]; //result file name ex. dt_result.txt
    
    IO ioclass(trainFile,testFile,resultFile);
    ioclass.fileRead();
    DecisionTree dtree(ioclass.getTrainSet(),ioclass.getTestSet());
    dtree.run();
    ioclass.createOutputFile(dtree.getTestResult());
    return 0;
}
