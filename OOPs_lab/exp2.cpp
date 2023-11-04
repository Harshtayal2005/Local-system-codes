// write a program to add two values of different data types using static polymorphism
#include<iostream>
#include<string>
using namespace std;

int add(int n1, int n2){
    return n1+n2;
}
void add(string num1, string num2){
    cout<<"concatenated string is: "<<num1+num2<<endl;
}
int main(){
    int n1 = 3, n2 = 4;
    cout<<"addition of n1 and n2 is: "<<add(n1,n2)<<endl;
    
    add("harsh", "tayal");

    return 0;
}