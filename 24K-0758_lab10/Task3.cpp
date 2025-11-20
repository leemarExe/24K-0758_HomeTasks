#include<iostream>
using namespace std;


struct Task{
    string id;
    int priority;
};


class MaxHeap{
    private:
    Task* heap;
    int size;
    int capacity;

    void heapifyUp(int index){
        if(index <= 0) return;

        int parent = (index - 1) / 2;
        if(heap[parent].priority < heap[index].priority){
            swap(heap[parent], heap[index]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index){
        int largest = index;

        int leftChild = 2 * index + 1;
        int rightChild = 2* index + 2;

        if(leftChild < size && heap[leftChild].priority > heap[largest].priority){
            largest = leftChild;
        }
        if(rightChild < size && heap[rightChild].priority > heap[largest].priority){
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
        heap = new Task[capacity];
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == capacity;
    }

    void insert(string id, int priority){
        if(isFull()){
            cout << "Heap is full.\n";
            return;
        }
        heap[size] = {id, priority};
        heapifyUp(size);
        size += 1;
    }

    Task remove(){
        if(isEmpty()){
            cout << "Heap is empty.\n";
            return {"", -1};
        }

        Task maxVal = heap[0];
        heap[0] = heap[size - 1];
        size -= 1;
        heapifyDown(0);
        return maxVal;
    }

    void displayHeap(){
        for(int i=0;i<size;i++)
            cout << heap[i].id << "(" << heap[i].priority << ") ";
        cout << endl;
    }
};



int main(){

    MaxHeap mh(10);

    mh.insert("A",5);
    mh.insert("B",3);
    mh.insert("C",8);

    mh.displayHeap();

    Task removed = mh.remove();
    mh.displayHeap();

    mh.insert("D",6);
    mh.displayHeap();

    return 0;

} 