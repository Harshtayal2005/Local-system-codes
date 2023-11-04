#include<iostream>
#include<string>
using namespace std;

bool compare(string s, string t){
    if(s==t){
        return 1;
    }
    else{
        return 0;
    }
}
string countSort(string &str){
    int n = str.size();
    int freqArr[26]={0};
    for(int i=0; i<n; i++){
        freqArr[int(str[i]-'a')]++;
    }
    int k=0;
    for(int j=0; j<26; j++){
        while(freqArr[j]--){
            str[k++]=char(j+97);
        }
    }
    return str;
    
}


int main(){
    string s="bank";
    string t="atm";
    countSort(s);
    countSort(t);
    int ans = compare(s,t);
    if(ans){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
    cout<<endl;
    return 0;
}