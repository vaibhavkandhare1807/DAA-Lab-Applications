#include <bits/stdc++.h>
using namespace std;

struct Product{
    int id;
    string name;
    float price;
};

int partition(vector<Product>& p,int low,int high){
    float pivot=p[high].price;
    int i=low-1;
    for(int j=low;j<high;j++){
        if(p[j].price<pivot){
            i++;
            swap(p[i],p[j]);
        }
    }
    swap(p[i+1],p[high]);
    return i+1;
}

void quickSort(vector<Product>& p,int low,int high){
    if(low<high){
        int pi=partition(p,low,high);
        quickSort(p,low,pi-1);
        quickSort(p,pi+1,high);
    }
}

int main(){
    int n;
    cout<<"Enter number of products: ";
    cin>>n;
    vector<Product> p(n);
    cout<<"Enter product details (ID Name Price):\n";
    for(int i=0;i<n;i++) cin>>p[i].id>>p[i].name>>p[i].price;
    quickSort(p,0,n-1);
    cout<<"\nProducts sorted by price (ascending):\n";
    for(int i=0;i<n;i++) cout<<p[i].id<<" - "<<p[i].name<<" : Rs."<<p[i].price<<'\n';
    return 0;
}
