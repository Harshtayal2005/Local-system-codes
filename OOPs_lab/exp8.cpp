// WAP to reverse a string using recursion
#include<iostream>
#include<string>
using namespace std;

void revString(string &s, int si, int ei){
    if(si>ei){
        return;
    }
    swap(s[si], s[ei]);
    revString(s, si+1, ei-1);
}

int main(){
    string name = "harsh";
    cout<<"The rev of "<<name<<" is: ";
    revString(name, 0, name.length()-1);
    cout<<name<<endl;
    return 0;
}