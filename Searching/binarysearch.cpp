#include<iostream>
using namespace std;

bool binarySearch(int *arr, int size, int key){
    int si = 0, ei = size-1;
    int mid = si + (ei-si)/2;
    while(si<=ei){
        if(key == arr[mid]){
            return 1;
        }
        else if(key>arr[mid]){
            si = mid+1;
        }
        else{
            ei = mid-1;
        }
        mid = si + (ei-si)/2;
    }
    return 0;
}
int main(){
    int arr[]={2,3,4,5,6,7};
    int n = 6, key = 2;
    bool ans = binarySearch(arr, n, key);
    if(ans){
        cout<<"Present"<<endl;
    } else{
        cout<<"Absent"<<endl;
    }
    return 0;
}