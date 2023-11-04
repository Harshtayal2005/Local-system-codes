// WAP for binary search using recursion
#include<iostream>
using namespace std;

int search(int arr[], int key, int si, int ei){
    int mid = si+(ei-si)/2;
    if(si>ei){
        return -1;
    }
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        return search(arr, key, si, mid-1);
    }
    else{
        return search(arr, key, mid+1, ei);
    }
    
}

int main(){
    int arr[]={3,4,5,10,11,23};
    int key = 5;
    int n = 6;
    int ans = search(arr, key, 0, n-1);
    if(ans!=-1){
        cout<<"The key is found at index: "<<ans<<endl;
    }
    else{
        cout<<"The key is not found"<<endl;
    }
    return 0;
}