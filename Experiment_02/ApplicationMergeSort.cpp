#include <bits/stdc++.h>
using namespace std;

struct Student{
    int rollNo;
    string name;
    float marks;
};

void merge(vector<Student>& s,int left,int mid,int right){
    int n1=mid-left+1,n2=right-mid;
    vector<Student> L(n1),R(n2);
    for(int i=0;i<n1;i++) L[i]=s[left+i];
    for(int j=0;j<n2;j++) R[j]=s[mid+1+j];
    int i=0,j=0,k=left;
    while(i<n1&&j<n2){
        if(L[i].marks>=R[j].marks) s[k++]=L[i++];
        else s[k++]=R[j++];
    }
    while(i<n1) s[k++]=L[i++];
    while(j<n2) s[k++]=R[j++];
}

void mergeSort(vector<Student>& s,int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(s,left,mid);
        mergeSort(s,mid+1,right);
        merge(s,left,mid,right);
    }
}

int main(){
    int n;
    cout<<"Enter number of students: ";
    cin>>n;
    vector<Student> s(n);
    cout<<"Enter student details (RollNo Name Marks):\n";
    for(int i=0;i<n;i++) cin>>s[i].rollNo>>s[i].name>>s[i].marks;
    mergeSort(s,0,n-1);
    cout<<"\nStudents sorted by marks (descending order):\n";
    for(int i=0;i<n;i++) cout<<s[i].rollNo<<" - "<<s[i].name<<" : "<<s[i].marks<<" marks\n";
    return 0;
}
