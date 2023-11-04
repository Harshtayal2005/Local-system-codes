#include<iostream>
using namespace std;


void countSort(int arr[], int n){
    int freqArr[10]={0};
    for(int i=0; i<n; i++){
        freqArr[arr[i]]++;
    }
    int k=0;
    for(int j=0; j<10; j++){
        while(freqArr[j]--){
            arr[k++] = j;
        }
    }
    
}


int main(){
    int arr[]={9,2,3,5,1,0,3};
    countSort(arr, 7);
    for(int ele:arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}