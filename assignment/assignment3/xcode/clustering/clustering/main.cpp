#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

struct objectInfo{
    int id;
    double xpos,ypos;
};

class Clustering{
private:
    int sz,n,eps,minpts;
    vector<objectInfo>obj;//object location
    vector<vector<double>>dist;
    vector<bool>checker;
    vector<vector<int>>result;
public:
    Clustering(int _n, int _eps, int _minpts,vector<objectInfo> object){
        sz=int(object.size());
        n=_n;
        eps=_eps;
        minpts=_minpts;
        obj=object;
        dist.resize(sz);
        for(int i=0;i<sz;i++)
            dist[i].resize(sz);
        checker.resize(sz);
    }
    void run(){
        calculateAllDistances();
        dbscan();
    }
    void calculateAllDistances(){
        for(int i=0;i<sz;i++)
            dist[i][i]=0;
        
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                dist[i][j]=dist[j][i]=calculateDistance(obj[i],obj[j]);
                
            }
        }
    }
    double calculateDistance(objectInfo p1, objectInfo p2){
        return sqrt(pow(p1.xpos-p2.xpos,2)+pow(p1.ypos-p2.ypos,2));
    }
    void dbscan(){
        for(int i=0;i<sz;i++){
            if(checker[i])continue;
            vector<int>cluster={};
            discoverCluster(i,cluster);
            if(cluster.size()>1)
                result.push_back(cluster);
        }
    }
    void discoverCluster(int i,vector<int>& cluster){
        checker[i]=true;
        cluster.push_back(obj[i].id);
        int pts=0;
        for(int p=0;p<sz;p++){
            if(dist[i][p]<=eps)pts++;
        }
        if(pts>=minpts){
            for(int p=0;p<sz;p++){
                if(checker[p] || dist[i][p]>eps)continue;
                discoverCluster(p, cluster);
            }
        }
    }
    vector<vector<int>> getResult(){
        if(result.size()>n){
            sort(result.begin(),result.end(),[](vector<int>a, vector<int>b){
                return a.size()>b.size();
            });
            while(result.size()>n)
                result.pop_back();
        }
        return result;
    }
};
class IO{
private:
    int n;
    string inputFile;
    string outputFile;
    ifstream readFile;
    ofstream writeFile;
    vector<objectInfo>object;
public:
    IO(int _n, string input){
        n=_n;
        inputFile=input;
        string str=inputFile;
        stringstream ss(str);
        string tmp;
        getline(ss,tmp,'.');
        outputFile=tmp;
    }
    void inputRead(){
        readFile.open(inputFile);
        if(readFile.is_open()) {
            string s;
            while(getline(readFile, s))
                object.push_back(split(s, '\t'));
            readFile.close();
        }
        else{
            cout << "Input file is not opened\n";
            exit(0);
        }
    }
    void createOutputFile(vector<vector<int>>result){
        for(int i=0;i<n;i++){
            writeFile.open(outputFile+"_cluster_"+to_string(i)+".txt");
            if(writeFile.is_open()) {
                for(int id:result[i])
                    writeFile<<id<<"\n";
                writeFile.close();
            }
            else{
                cout << "Ouput file is not opened\n";
                exit(0);
            }
        }
    }
    objectInfo split(string str, char delimiter) {
        objectInfo tmp;
        stringstream ss(str);
        string temp;
        getline(ss,temp,delimiter);
        tmp.id=stoi(temp);
        getline(ss,temp,delimiter);
        tmp.xpos=stod(temp);
        getline(ss,temp,delimiter);
        tmp.ypos=stod(temp);
        return tmp;
    }
    vector<objectInfo> getObject(){
        return object;
    }
};

int main(int argc, const char * argv[]) {
    string inputFile=argv[1];
    int n=stoi(argv[2]);
    int eps=stoi(argv[3]);
    int minpts=stoi(argv[4]);
    IO ioclass(n, inputFile);
    ioclass.inputRead();
    Clustering clustering(n,eps,minpts,ioclass.getObject());
    clustering.run();
    ioclass.createOutputFile(clustering.getResult());
    return 0;
}
