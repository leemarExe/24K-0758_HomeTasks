#include<iostream>
using namespace std;


class MaxHeap{
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

    void heapifyDown(int index){
        int largest = index;

        int leftChild = 2 * index + 1;
        int rightChild = 2* index + 2;

        if(leftChild < size && heap[leftChild] > heap[largest]){
            largest = leftChild;
        }
        if(rightChild < size && heap[rightChild] > heap[largest]){
            largest = rightChild;
        }
        if(largest != index){
            swap(heap[largest], heap[index]);
            heapifyDown(largest);
        }
    }

    public:
    MaxHeap(int cap) : capacity(cap){
        size = 0;
        heap = new int[capacity];
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == capacity;
    }

    void insert(int price){
        if(isFull()){
            cout << "Heap is full.\n";
            return;
        }
        heap[size] = price;
        heapifyUp(size);
        size += 1;
    }

    void remove(){
        if(isEmpty()){
            cout << "Heap is empty.\n";
            return;
        }

        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size -= 1;
        heapifyDown(0);
    }

    void displayHeap(){
        for(int i = 0 ; i < size ; i++){
            cout << heap[i] << " " ;
        }
        cout << endl;
    }
};

int main(){

    MaxHeap myheap(10);

    myheap.insert(100);
    myheap.insert(50);
    myheap.insert(75);
    myheap.insert(60);
    myheap.displayHeap();
    
    myheap.insert(55);
    myheap.displayHeap();
    
    myheap.remove();
    myheap.displayHeap();
}