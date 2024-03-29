#include<iostream>
using namespace std;
//implementation using array
// class queue{
//     public:
//     int* arr;
//     int qfront;
//     int rear;
//     int qsize;

//     queue(int size){
//         this->qsize = size;
//         arr = new int[size];
//         qfront=0;
//         rear=0;// will denote the empty space and if rear==-1 then it will denote the filled space
//     }
//     void push(int element){
//         if(rear==qsize){
//             cout<<"queue is full"<<endl;
//             return ;
//         }
//         else{
//             arr[rear]=element;
//             rear++;
//             return;
            
//         }
//     }
//     void pop(){
//         if(qfront==rear){
//             cout<<"queue is empty"<<endl;
//         }
//         else{
//             arr[qfront]=-1;
//             qfront++;
//             if(qfront==rear){
//                 qfront=0;
//                 rear=0;
//             }
//         }
//     }
//     int size(){
//         if(qfront==rear){
//             return -1;
//         }
//         return rear-qfront;
//     }
//     int front(){
//         if(qfront==rear){
//             return -1;
//         }
//         return arr[qfront];
//     }
//     bool isempty(){
//         if(qfront==rear){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }

// };

// int main(){
//     queue q(5);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.push(1);
//     q.push(2);
//     q.push(1);
//     cout<<q.front()<<endl;
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
class queue{
    public:
    Node* front;
    Node* rear;

    queue(){
        front = NULL;
        rear = NULL;
    }

    void push(int data){
        Node* temp = new Node(data);
        if(!temp){
            cout<<"queue is full"<<endl;
            return;
        }
        if(rear==NULL){
            front = temp;
            rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void pop(){
        if(front==NULL){
            cout<<"queue is empty"<<endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        free(temp);
    }
    int peek(){
        if(front==NULL){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty(){
        if(front==NULL){
            return true;
        }
        else
        return false;
    }
};
int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<q.peek()<<endl;
    if(q.isEmpty()){
        cout<<"empty"<<endl;
    }
    else
    cout<<"not empty"<<endl;
    return 0;
}