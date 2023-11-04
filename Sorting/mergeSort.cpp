#include<iostream>
using namespace std;

void merge(int arr[], int si, int ei, int mid){
    int i = si, j = mid+1, k = 0;
    int m = mid-si+1;
    int n = ei-mid;
    int *sortedArray = new int[m+n];
    
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            sortedArray[k] = arr[i];
            i++;
            k++;
        }
        else if(arr[i]>arr[j]){
            sortedArray[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        sortedArray[k] = arr[i];
        i++;
        k++;
    }
    while(j<=ei){
        sortedArray[k] = arr[j];
        j++;
        k++;
    }
    for(int idx = 0 ; idx<(ei-si+1); idx++){
        arr[idx+si] = sortedArray[idx];
    }
    delete[] sortedArray;
}

void mergeSort(int arr[], int si, int ei){
    if(si>=ei){
        return ;
    }
    int mid = si + (ei - si)/2;
    // left sorting
    mergeSort(arr, si, mid);
    //right sorting
    mergeSort(arr, mid+1, ei);
    merge(arr, si, ei, mid);
}


int main(){
    int arr[]= {5,5,4,3,2,1};
    int n = 6;
    mergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
    return 0;
}
//   OR
// #include<iostream>
// #include<vector>
// using namespace std;

// void merge(int arr[], int si, int ei){
//     int mid = si+(ei-si)/2;
//     int n = mid-si+1;
//     int m = ei-mid;
//     int *leftArr = new int[n];
//     int *rightArr = new int[m];
//     int mainArrIdx=si;
//     for(int i=0; i<n; i++){
//         leftArr[i]=arr[mainArrIdx++];
//     }
//     mainArrIdx=mid+1;
//     for(int j=0; j<m; j++){
//         rightArr[j]=arr[mainArrIdx++];
//     }
//     int i=0, j=0;
//     int mainArr = si;
//     while(i<n && j<m){
//         if(leftArr[i]<=rightArr[j]){
//             arr[mainArr++]=leftArr[i++];
//         }
//         else{
//             arr[mainArr++]=rightArr[j++];
//         }
//     }
//     while(i<n){
//         arr[mainArr++]=leftArr[i++];
//     }
//     while(j<m){
//         arr[mainArr++]=rightArr[j++];
//     }
    
// }

// void mergeSort(int arr[], int si, int ei){
//     if(si>=ei){
//         return ;
//     }
//     int mid = si+(ei-si)/2;
//     mergeSort(arr, si, mid);
//     mergeSort(arr, mid+1, ei);
//     merge(arr, si, ei); 
// }
// int main(){
//     int arr[]={4,3,6,7,1,2};
//     int n = 6;
//     mergeSort(arr, 0, n-1);
//     for(int ele:arr){
//         cout<<ele<<" ";
//     }
//     cout<<endl;
//     return 0;
// }