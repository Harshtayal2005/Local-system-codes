#include<iostream>
using namespace std;
//implementation using array
// class stack{
//     public:
//     int *arr;
//     int top; 
//     int size;

//     stack(int size){
//         this->size = size;
//         arr = new int[size];
//         top=-1; //denotes the top element of the stack
//     }

//     void push(int element){
//         if(size-top>1){
//             top++;
//             arr[top]=element;
//         }
//         else{
//             cout<<"stack overflow"<<endl;
//         }
//     }
//     void pop(){
//         if(top>=0){
//             top--;
//         }
//         else{
//             cout<<"stack underflow"<<endl;
//         }
//     }
//     int peek(){
//         if(top>=0){
//             return arr[top];
//         }
//         else{
//             cout<<"stack is empty"<<endl;
//             return -1;
//         }
//     }
//     bool isempty(){
//         if(top==-1){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };

// int main(){
//     stack s(5);
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     s.push(5);
//     s.push(7);
//     cout<<s.peek()<<endl;
//     if(s.isempty()){
//         cout<<"stack is empty"<<endl;
//     }
//     else{
//         cout<<"stack is not empty"<<endl;
//     }
//     return 0;
// }

//implementation using linked list
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};
class stack{
    public:
    Node* top;
    stack(){
        top = NULL;
    }

void push(int data){
    Node* temp = new Node(data);
    if(!temp){
        cout<<"stack overflow"<<endl;
        return;
    }
    temp->next = top;
    top = temp;
}
void pop(){
    if(top==NULL){
        cout<<"stack empty"<<endl;
        return;
    }
    top = top->next;
}
bool isEmpty(){
    if(top==NULL){
        return true;
    }
    else
    return false;
}
int peek(){
    if(top==NULL){
        cout<<"stack empty"<<endl;
        return -1;
    }
    return top->data;
}
};
int main(){
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout<<s1.peek()<<endl;
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    cout<<s1.peek()<<endl;
    if(s1.isEmpty()){
        cout<<"empty"<<endl;
    }
    else{
        cout<<"not empty"<<endl;
    }
    return 0;
}
