#include<iostream>
#include<queue>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size+1;
        int index = size;
        // inserting in sequential position
        arr[index] = val;
        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                // correcting the position
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deleteFromHeap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        // put last element in first index
        arr[1] = arr[size];
        // removing the last element
        size--;
        int idx = 1;
        // correcting the root node position
        while(idx<size){
            int leftChild = 2*idx;
            int rightChild = (2*idx)+1;
            if(leftChild < size && arr[idx] < arr[leftChild]){
                swap(arr[idx], arr[leftChild]);
                idx = leftChild;
            }
            else if(rightChild < size && arr[idx] < arr[rightChild]){
                swap(arr[idx], arr[rightChild]);
                idx = rightChild;
            }
            else{
                return;
            }
        }
    }
};
//for 1 based indexing 
//if 0-based indexing then left = 2*i + 1 and right = 2*i + 2
void heapify(int arr[], int n, int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i + 1;

        if(left <= n && arr[largest] < arr[left]){
            largest = left;
        }
        if(right <= n && arr[largest] < arr[right]){
            largest = right;
        }

        if(largest!=i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
}
void heapSort(int arr[], int n){
    int size = n;
    while(size>1){
    swap(arr[1], arr[size]);
    size--;
    heapify(arr, size, 1);
    }
}

int main(){
    heap h;
    h.insert(54);
    h.insert(53);
    h.insert(55);
    h.insert(52);
    h.insert(50);
    h.print();
    h.deleteFromHeap();
    h.print();
    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }
    heapSort(arr, n);
    for(int ele : arr){
        cout<<ele<<" ";
    }
    
    cout<<"Using priority queue: "<<endl;
    //max heap
    priority_queue<int> pq;
    pq.push(2);
    pq.push(1);
    pq.push(8);
    pq.push(7);
    cout<<pq.top()<<endl; // should print max element
    pq.pop();
    cout<<pq.top()<<endl; // should print 2nd largest element
    cout<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"heap is empty"<<endl;
    }
    else{
        cout<<"Not empty"<<endl;
    }
    cout<<endl;
    // min heap
    priority_queue<int, vector<int>, greater<int> > minHeap;
    minHeap.push(2);
    minHeap.push(1);
    minHeap.push(8);
    minHeap.push(7);
    cout<<minHeap.top()<<endl; // should print smallest element
    minHeap.pop();
    cout<<minHeap.top()<<endl; // should print 2nd smallest element
    cout<<minHeap.size()<<endl;
    if(minHeap.empty()){
        cout<<"heap is empty"<<endl;
    }
    else{
        cout<<"Not empty"<<endl;
    }
    return 0;
}