#include<iostream>
using namespace std;

int partition(int arr[], int si, int ei){
    int pivot = arr[si];
    int count = 0;
    for(int i=si+1; i<=ei; i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    int pivotIndex = count+si;
    swap(arr[si], arr[pivotIndex]);
    int i = si, j = ei;
    while(i<pivotIndex && j>pivotIndex){
        if(arr[i]>pivot && arr[j]<=pivot){
            swap(arr[i++], arr[j--]);
        }
        else if(arr[i]>pivot){
            j--;
        }
        else{
            i++;
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int si, int ei){
    if(si>=ei){
        return ;
    }
    int partIndex = partition(arr, si, ei);

    quickSort(arr, si, partIndex-1);
    quickSort(arr, partIndex+1, ei);
}

int main(){
    int arr[]={6,4,2,33,8,9,8,11,3,4,5,1,1,2};
    int n = 14;
    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
    return 0;
}