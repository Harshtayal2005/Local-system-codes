#include<iostream>
using namespace std;
bool issorted(int *arr, int size){
    if(size==0 || size==1){
        return true;
    }
    else if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool remainingpart=issorted(arr+1, size-1 );
        return remainingpart;
    }
}
int main(){
    int arr[]={2,4,5,1,7,8};
    int size=6;
    bool ans=issorted(arr,size);
    if(ans){
        cout<<"The array is sorted"<<endl;
    } else{
        cout<<"The array is not sorted"<<endl;
    }
    return 0;
}