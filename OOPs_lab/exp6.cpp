// WAP for X power Y through recursion
#include<iostream>
using namespace std;

int power(int a, int b){
    if(b==0){
        return 1;
    }
    return a*power(a,b-1);
}
int main(){
    int a = 0;
    int b = 3;
    float ans;
    if(b>=0){
    ans = power(a,b);
    }
    else{
        ans = 1.0/power(a,-b);
    }
    if(ans==INFINITY){
        cout<<"Undefined"<<endl;
    }
    else
    cout<<a<<" to the power "<<b<<" is "<<ans<<endl;
    return 0;
}