#include<iostream>
using namespace std;



class MinHeap{
    private:
    int* heap;
    int size;
    int capacity;

    void heapifyUp(int index){
        if(index <= 0) return;

        int parent = (index - 1) / 2;
        if(heap[parent] < heap[index]){
            swap(heap[parent], heap[index]);
            heapifyUp(parent);
        }
    }
    
    public:
    MinHeap(int cap) : capacity(cap){
        size = 0;
        heap = new int[capacity];
    }

    bool isFull(){
        return size == capacity;
    }

    void insert(int val){
        if(isFull()){
            cout << "Heap is full.\n";
            return;
        }
        heap[size] = val;
        heapifyUp(size);
        size += 1;
    }

    void displayHeap(){
        for(int i = 0 ; i < size ; i++){
            cout << heap[i] << " " ;
        }
        cout << endl;
    }
};


int main() {

    MinHeap mh(20);

    mh.insert(1);
    mh.insert(3);
    mh.insert(4);
    mh.insert(5);
    mh.displayHeap();

    mh.insert(2);
    mh.displayHeap();

    return 0;
}