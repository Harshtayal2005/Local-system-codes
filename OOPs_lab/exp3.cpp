//WAP to that find the absolute value of a number using function overloading.
#include<iostream>
using namespace std;
int absolute(int num){
    if(num<0){
        return -num;
    }
    return num;

}
double absolute(double num){
    if(num<0.0){
        return -num;
    }
    return num;
}
int main(){
    int n1 = -3;
    double n2 = -4.5;
    cout<<"The absolute value of n1 is: "<<absolute(n1)<<endl;
    cout<<"The absolute value of n2 is: "<<absolute(n2)<<endl;
    return 0;
}