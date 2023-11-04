// WAP to print fibonacci series using recursion
#include<iostream>
using namespace std;

int printFibonacci(int n){
    if(n<=0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return printFibonacci(n-1)+printFibonacci(n-2);
}

int main(){
    int n = 1;
    cout<<"The fibonacci series from 0th to "<<n<<"th is: ";
    for(int i=0; i<=n; i++){
        cout<<printFibonacci(i)<<" ";
    }
    cout<<endl;
    return 0;
}