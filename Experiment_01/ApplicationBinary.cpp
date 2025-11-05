#include<bits/stdc++.h>
using namespace std;
struct Customer{
    int id;
    string name;
};
int binarySearchCustomer(vector<Customer>& customers,int low,int high,int targetID){
    if(low>high)
        return -1;
    int mid=(low+high)/2;
    
    if(customers[mid].id==targetID)
        return mid;
    else if(targetID<customers[mid].id)
        return binarySearchCustomer(customers,low,mid-1,targetID);
    else
        return binarySearchCustomer(customers,mid+1,high,targetID);
}
int main(){
    int n;
    cout<<"Enter number of customers: ";
    cin>>n;
    vector<Customer> customers(n);
    cout<<"Enter customer details (ID Name):\n";
    for(int i=0;i<n;i++)
        cin>>customers[i].id>>customers[i].name;
    sort(customers.begin(),customers.end(),[](Customer a,Customer b){
        return a.id<b.id;
    });
    int targetID;
    cout<<"Enter Customer ID to search: ";
    cin>>targetID;
    int result=binarySearchCustomer(customers,0,customers.size()-1,targetID);
    if(result!=-1)
        cout<<"Customer Found: "<<customers[result].name<<" (ID: "<<customers[result].id<<")\n";
    else
        cout<<"Customer not found in the database.\n";
    return 0;
}
