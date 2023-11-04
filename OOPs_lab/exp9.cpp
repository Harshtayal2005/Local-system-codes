// bank account
#include<iostream>
using namespace std;

class Account{
    public:
    char name[100];
    int acc_no;
    char acc_type;
    double total_amt;
    void input(){
        cout<<"Enter the name of the account holder: ";
        cin>>name;
        cout<<"Enter the account number: ";
        cin>>acc_no;
        cout<<"Enter the account type(S or C): ";
        cin>>acc_type;
        cout<<"Enter the amount to add: ";
        cin>>total_amt;
    }
    void deposit(){
        cout<<"Enter the amount to be deposited: ";
        double x;
        cin>>x;
        total_amt+=x;
        cout<<"money deposited"<<endl;
        return;
    }
    void withdraw(){
        cout<<"Enter the amount to withdraw: ";
        double x;
        cin>>x;
        if(total_amt>1000.0){
            if(x < total_amt){
            total_amt-=x;
            cout<<"Money withdrawl succesful"<<endl;
            }
            else{
                cout<<"Not enough balance"<<endl;
            }
            return;
        }
        else{
            cout<<"Balance is less than 1000, money can't be withdrawn"<<endl;
            return;
        }
    }
    void display(){
        cout<<"Account holder is: "<<name<<endl;
        cout<<"Account number is: "<<acc_no<<endl;
        cout<<"Account type is: "<<acc_type<<endl;
        cout<<"Total amount is: "<<total_amt<<endl;
    }
};
int main(){
    Account a1;
    a1.input();
    cout<<endl;
    a1.deposit();
    cout<<endl;
    a1.withdraw();
    cout<<endl;
    a1.display();
    return 0;
}