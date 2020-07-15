#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <set>
#include <sstream>
#include <math.h>

using namespace std;

typedef pair<vector<int>,int> pvi;
typedef vector<int> vi;

struct association{
    vi xItemset;
    vi yItemset;
    double support;
    double confidence;
};

class AprioriProject{
private:
    int numOfScan;
    double minSupport;
    vector<vi>transactions;
    vector<vi> candidates;
    vector<map<vi,double>>frequentItemsets;
    vector<association> associationRules;
public:
    AprioriProject(double minSup,vector<vi>trans){
        numOfScan = 0;
        minSupport = minSup;
        transactions.assign(trans.begin(),trans.end());
        map<vi,double>tmp;
        tmp.insert(pvi({},0));
        frequentItemsets.push_back(tmp);//for index 0
    }
    void run(){
        while(true){
            candidates = generateCandidates();
            if(candidates.size()==0)break;
            numOfScan++;
            findFrequentItems();
            for(auto frequentItems:frequentItemsets[numOfScan])
                generateAssociationRule(frequentItems.first);
        }
    }
    vector<association> getAssociationRules(){
        return associationRules;
    }
    vector<vector<int>> generateCandidates(){
        if(numOfScan==0){
            set<int>s;
            vector<vi>c;
            for(auto transaction:transactions)
                for(auto item:transaction)
                    s.insert(item);
            for(auto item:s)
                c.push_back({item});
            return c;
        }
        else{
            //joining and pruning
            vector<vi> joinedItems=joining();
            return pruning(joinedItems);
        }
    }
    vector<vi> joining(){
        map<vi,double>prevL=(map<vi,double>)frequentItemsets[numOfScan];
        vector<vi> joinedItems;
        //self-joining
        for(pvi L1:prevL){
            for(pvi L2:prevL){
                if(L1>=L2)continue;
                int cnt=0;
                for(int k=0;k<numOfScan-1; k++) {
                    if(L1.first[k] == L2.first[k])
                        cnt++;
                }
                if(cnt == numOfScan-1) {
                    vi unionVector;
                    unionVector.resize((int)(L1.first.size()));
                    copy(L1.first.begin(),L1.first.end(),unionVector.begin());
                    unionVector.push_back(L2.first[numOfScan-1]);
                    if(unionVector[numOfScan-1]>unionVector[numOfScan])
                        swap(unionVector[numOfScan-1],unionVector[numOfScan]);
                    joinedItems.push_back(unionVector);
                }
            }
        }
        return joinedItems;
    }
    vector<vi> pruning(vector<vi>joinedItems){
        vector<vi>c;
        map<vi,double>prevL=(map<vi,double>)frequentItemsets[numOfScan];
        //pruning
        for(auto candidate:joinedItems){
            int cnt=0;
            for(int i=0;i<candidate.size();i++){
                vi tmp = candidate;
                tmp.erase(tmp.begin()+i);
                if(prevL.find(tmp) == prevL.end()){
                    cnt++;
                    break;
                }
            }
            if(cnt==0)
                c.push_back(candidate);
        }
        return c;
    }
    void findFrequentItems(){
        map<vi,double>frequent;
        for(auto candidate:candidates){
            double support=0.0;
            for(auto transaction:transactions){
                int cnt=0;
                for(auto item:candidate){
                    if(find(transaction.begin(),transaction.end(),item)==transaction.end()){
                        cnt++;
                        break;
                    }
                }
                if(cnt==0)
                    support+=1.0;
            }
            support = support/transactions.size()*100;
            if(support>=minSupport){
                frequent[candidate]=support;
            }
        }
        frequentItemsets.push_back(frequent);
    }
    void generateAssociationRule(vi items){
        double support = frequentItemsets[numOfScan][items];
        for(int i=1;i<numOfScan;i++){
            for(auto pair:frequentItemsets[i]){
                vi xItemset;
                vi yItemset;
                map<int,bool>xChecker;

                for(int item:pair.first)
                    xChecker[item]=true;
                int xcnt=int(xChecker.size());
                int ycnt=0;
                for(int item:items){
                    if(xChecker.find(item)==xChecker.end()){
                        yItemset.push_back(item);
                        ycnt++;
                    }
                }
                if(xChecker.size()+ycnt==items.size()){
                    for(auto item:xChecker)
                        xItemset.push_back(item.first);
                    double xconfidence = support/frequentItemsets[xcnt][xItemset]*100;
                    xconfidence = round(xconfidence*100)/100;
                    associationRules.push_back({xItemset,yItemset,support,xconfidence});
                }
            }
        }
    }
};

class IO{
private:
    string inputFile;
    string outputFile;
    ifstream readFile;
    ofstream writeFile;
    vector<vi>transactions;
public:
    IO(string input, string output){
        inputFile=input;
        outputFile=output;
    }
    vector<vi> getTransactions(){
        return transactions;
    }
    void inputRead(){
        readFile.open(inputFile);
        if(readFile.is_open()) {
            string s;
            while(getline(readFile, s)){
                vector<int> tmp;
                vi parse = split(s,'\t');
                if(parse.size()>0){
                    transactions.push_back(parse);
                }
            }
            readFile.close();
        }
        else{
            cout << "Input file is not opened\n";
            exit(0);
        }
    }
    void createOutputFile(vector<association> associationRules){
        writeFile.open(outputFile);
        writeFile.precision(2);
        writeFile.setf(ios::fixed);
        writeFile.setf(ios::showpoint);
        if(writeFile.is_open()) {
            for(association item:associationRules){
                writeFile<<itemsetToStr(item.xItemset)<<'\t';
                writeFile<<itemsetToStr(item.yItemset)<<'\t';
                writeFile<<item.support<<'\t';
                writeFile<<item.confidence<<'\n';
            }
            writeFile.close();
        }
        else{
            cout << "Ouput file is not opened\n";
            exit(0);
        }
    }
    string itemsetToStr(vector<int> itemSet) {
        string str = "{";
        for(int item:itemSet){
            str += to_string(item);
            if(item != itemSet.back())
                str += ",";
        }
        str += "}";
        return str;
    }
    vector<int> split(string str, char delimiter) {
        vector<int> ret;
        stringstream ss(str);
        string temp;
        while (getline(ss, temp, delimiter))
            ret.push_back(stoi(temp));
        return ret;
    }
};

int main(int argc, char ** argv){
    double minSup = stod(argv[1]); //min support
    string inputFile = argv[2]; //input file name ex. input.txt
    string outputFile = argv[3]; //output file name ex. output.txt

    IO ioclass(inputFile, outputFile);
    ioclass.inputRead();
    AprioriProject apriori(minSup,ioclass.getTransactions());
    apriori.run();
    ioclass.createOutputFile(apriori.getAssociationRules());

    return 0;
}
