#include<iostream>
#include<vector>
#include<string>

using namespace std;

class hero{
    public:
    char* name;
    int health=8;
    char level;
    static int timeToComplete;
    //default constructor
    hero(){
        cout<<"simple constructor called"<<endl;
    }
    //parameterised constructor
    // hero(int health){
    //     this->health = health;
    // }
    //copy constructor
    // hero(hero& temp){
    //     char *ch = new char;
    //     strcpy(ch, temp.name);
    //     this->name = ch;
    // }
    void setName(char name[]){
        strcpy(this->name, name);
    }
    void setHealth(){

    }
    void setLevel(){

    }
    int getHealth(){
        return health;
    }
    void getLevel(){
        
    }
    ~hero(){
        cout<<"destructor called"<<endl;
    }
    
};
int hero::timeToComplete = 5;
int main(){
    hero h1;
    h1.timeToComplete=4;
    hero h2;
    cout<<h1.timeToComplete<<endl;
    cout<<h2.timeToComplete<<endl;

    return 0;
}