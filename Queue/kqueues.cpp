#include<iostream>
using namespace std;

class kqueue{

    public:
    int* arr;
    int n; // n is the size of array
    int k; // k is no of queues
    int* front;
    int* rear;
    int* next;
    int freeSpot;

    public:
        kqueue(int n, int k){
            this->n = n;
            this->k = k;
            arr = new int[n];
            front = new int[k];
            rear = new int[k];
            for(int i=0; i<k; i++){
                front[i]=-1;
                rear[i]=-1;
            }
            next = new int[n];
            for(int j=0; j<n; j++){
                next[j]=j+1;
            }
            next[n-1]=-1;
            freeSpot=0;
        }

        void enqueue(int data, int qn){
            if(freeSpot==-1){
                cout<<"overflow condition"<<endl;
                return;
            }
            int index = freeSpot;
            freeSpot = next[index];

            if(front[qn-1]==-1){
                front[qn-1] = index;
            }
            else{
                next[rear[qn-1]]=index;
            }
            rear[qn-1]=index;
            next[index]=-1;
            arr[index]=data;
        }

        int deque(int qn){
            if(front[qn-1]==-1){
                cout<<"Underflow condition"<<endl;
                return -1;
            }
        
            int index = front[qn-1];
            front[qn-1] = next[index];
            next[index] = freeSpot;
            freeSpot = index;

            return arr[index];

        }

};

int main(){
    kqueue q(5, 3);
    q.enqueue(11, 1);
    q.enqueue(13, 2);
    q.enqueue(14, 2);
    q.enqueue(11, 2);
    
    q.enqueue(12, 1);
    return 0;
}