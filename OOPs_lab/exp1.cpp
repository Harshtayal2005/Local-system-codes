//WAP to compute the volume of different shapes using function overloading.
#include<iostream>
using namespace std;
#define PI 3.14
// cube cuboid and cone
int volume(int a){
    return a*a*a;
}
int volume(int l, int b, int h1){
    return l*b*h1;
}
float volume(int r, int h2){
    return (PI*r*r*h2)/3;
}
int main(){
    int a = 2;
    cout<<"volume of cube is: "<<volume(a)<<endl;
    int l=3, b=5, h1=1;
    cout<<"volume of cuboid is: "<<volume(l, b, h1)<<endl;
    int r = 3, h2 = 4;
    cout<<"volume of cone is: "<<volume(r, h2)<<endl;
    return 0;
}