#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int low,int high,int key){
    if(low>high)
        return-1;
    int mid=(low+high) / 2;
    if(arr[mid]==key)
        return mid;
    else if(key<arr[mid])
        return binarySearch(arr,low,mid-1,key);
    else
        return binarySearch(arr,mid+1,high,key);
}
int main(){
    int n,key;
    cout<<"Enter the number of elements: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter "<< n<<" elements:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n); // Ensure array is sorted
    cout<<"Enter the element to search: ";
    cin>>key;

    int result=binarySearch(arr,0,n-1,key);

    if (result==-1)
        cout<<"Element not found in the array.\n";
    else
        cout<< "Element found at index "<<result<<"(0-based indexing).\n";
    return 0;
}
