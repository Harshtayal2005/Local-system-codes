#include<iostream>
using namespace std;
template <typename T>
class vec{
    public:
    T height;
    string name;
};
int main(){
    vec<int> obj;
    cout<<obj.height<<endl;
    return 0;
}