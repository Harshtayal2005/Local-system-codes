// WAP to calculate GCD usinf recursion
#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(a==b){
        return a;
    }
    if(a>b){
        return gcd(a-b, b);
    }
    else{
        return gcd(a, b-a);
    }
}

int main(){
    int a = 36;
    int b = 60;
    int ans = gcd(a,b);
    cout<<"The GCD of "<< a <<" and "<<b<<" is: "<<ans<<endl;
    return 0;
}