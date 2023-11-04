#include<iostream>
using namespace std;
void saydigits(int n){
    string name[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
        if(n==0){
            return ;
        }   
        int digit=n%10;

        n/=10;
        saydigits(n);
        cout<<name[digit]<<" ";

}
int main(){
    int n;
    cin>>n;
    saydigits(n);
    cout<<endl;
    return 0;
}