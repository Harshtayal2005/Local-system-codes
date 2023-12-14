#include<iostream>
using namespace std;


vector<int> countSort(vector<int> arr, int n, int maxEle){
    vector<int> count(maxEle + 1, 0);
    
    //storing the count of each element in count array
    for(auto& i : arr){
        count[i]++;
    }

    //finding the cumilative or prefix sum of count arraywhich tells how many elements present at index i 
    // are less than or equal to i
    for (int i = 1; i <= maxEle; i++){
        count[i] += count[i - 1];
    }

    // traversing from right to left in input array to maintain the relative order of equal elements
    vector<int> output = arr;

    for (int i = n-1; i >= 0; i--){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    return output;
}

int main(){
    vector<int> arr={9,2,3,5,1,0,3};

    vector<int>sortedarr = countSort(arr, 7, 9);

    for(auto& i : sortedarr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}