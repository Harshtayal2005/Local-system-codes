#include<iostream>
#include<vector>
using namespace std;

bool linearSearch(int arr[], int size, int key, int idx){
    if(idx==size){
        return false;
    }
    if(arr[idx]==key){
        return true;
    }
    else{
        return linearSearch(arr, size, key, idx+1);
    }
}
int main(){
    int arr[]={3,2,5,1,6};
    int size = 5;
    int key = 0;
    bool ans = linearSearch(arr, size, key, 0);
    if(ans){
        cout<<"Key is present"<<endl;
    }
    else{
        cout<<"Key is absent"<<endl;
    }
    return 0;
}