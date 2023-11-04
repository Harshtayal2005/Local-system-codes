// static member function
#include<iostream>
using namespace std;
class myClass{
    public:
    static int count;
    myClass(){
        count++;
    }
    static int getNoOfInstances(){
        return count;
    }
};
int myClass :: count = 0; 
int main(){
    myClass obj1;
    myClass obj2;
    myClass obj3;
    myClass obj4;
    int ans = myClass::getNoOfInstances();
    cout<<"Total objects created are: "<<ans<<endl;
    return 0;
}