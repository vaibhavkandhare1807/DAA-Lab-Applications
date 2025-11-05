#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
struct CampusFile{
    string campusName;
    int fileSize;// size in MB
};
struct Compare{
    bool operator()(CampusFile a,CampusFile b){
        return a.fileSize>b.fileSize;// Min-Heap
    }
};
int main(){
    int n;
    cout<<"Enter number of campus files: ";
    cin>>n;
    priority_queue<CampusFile, vector<CampusFile>, Compare> pq;
    cout<<"Enter campus name and file size (in MB):\n";
    for(int i=0;i<n;i++){
        CampusFile f;
        cin>>f.campusName>>f.fileSize;
        pq.push(f);
    }
    int totalCost=0;
    int step=1;
    cout<<"\n--- University Student Record Merge Simulation ---\n";
    while(pq.size()>1){
        CampusFile f1=pq.top(); pq.pop();
        CampusFile f2=pq.top(); pq.pop();
        int mergedSize=f1.fileSize+f2.fileSize;
        totalCost+=mergedSize;
        CampusFile merged={"Merged_"+to_string(step++),mergedSize};
        pq.push(merged);
        cout<<"Merged "<<f1.campusName<<" ("<<f1.fileSize<<" MB) + "<<f2.campusName<<" ("<<f2.fileSize<<" MB) -> "<<merged.campusName<<" ("<<mergedSize<<" MB)"<<" | Step Cost: "<<mergedSize<<endl;
    }
    cout<<"\nTotal merge cost (in MB): "<<totalCost<<endl;
    return 0;
}
