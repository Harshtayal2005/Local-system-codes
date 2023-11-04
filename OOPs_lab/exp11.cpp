// mean of two number using friend function
#include<iostream>
using namespace std;
class B;
class A{
    friend int add(A &o1, B &o2);
    int data1;
    public:
    void setData(int val){
        this->data1 = val;
    }
    
};
class B{
    friend int add(A &o1, B &o2);
    int data2;
    public:
    void setData(int val){
        this->data2 = val;
    }
    
};
int add(A &o1, B &o2){
    int ans = o1.data1 + o2.data2;
    return ans;
}
int main(){
    A o1;
    o1.setData(4);
    B o2;
    o2.setData(5);
    int res = add(o1, o2);
    cout<<res<<endl;
    return 0;
}