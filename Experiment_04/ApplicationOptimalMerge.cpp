#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct File{
    string name;
    int size;
};

struct compare{
    bool operator()(File a,File b){
        return a.size>b.size;
    }
};

int main(){
    int n;
    cout<<"Enter number of log files: ";
    cin>>n;

    priority_queue<File, vector<File>, compare> pq;
    cout<<"Enter file name and size (in MB):\n";
    for(int i=0;i<n;i++){
        File f;
        cin>>f.name>>f.size;
        pq.push(f);
    }

    int totalCost=0;
    int mergeCount=1;

    while(pq.size()>1){
        File f1=pq.top(); pq.pop();
        File f2=pq.top(); pq.pop();
        int mergeSize=f1.size+f2.size;
        totalCost+=mergeSize;
        File merged={"Merge"+to_string(mergeCount++), mergeSize};
        pq.push(merged);
        cout<<"Merged "<<f1.name<<" ("<<f1.size<<" MB) + "
            <<f2.name<<" ("<<f2.size<<" MB) -> "
            <<merged.name<<" ("<<mergeSize<<" MB)\n";
    }

    cout<<"\nTotal merge cost (in MB): "<<totalCost<<endl;
    return 0;
}
