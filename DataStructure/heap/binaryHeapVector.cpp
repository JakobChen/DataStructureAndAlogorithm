// C++ implementation of a binary heap

#include<iostream>
#include<vector>
using namespace std;

class BinaryHeap {
private:
    const static int MAX_SIZE = 15;
    //int heap[MAX_SIZE];
    vector<int> heap;
    int size;

public:
    BinaryHeap() {
        size = 0;
    }

    // returns the index of the parent node
    static int parent(int i) {
        return (i-1)/2;
    }

    // return the index of the left child 
    static int leftChild(int i) {
        return 2*i + 1;
    }

    // return the index of the right child 
    static int rightChild(int i) {
        return 2*i + 2;
    }

    static void swap(int &x, int &y) {
        int temp = x;
        x = y;
        y = temp;
    }

    // insert the item at the appropriate position
    void insert(int data) {
        if(heap.size()>MAX_SIZE){
            cout<<"Out of memory!";
            return;
        }
        heap.push_back(data); 
        
        //node index i = size-1;
        int i =heap.size()-1;
        while(!i && heap[parent(i)] < heap[i] ){
            swap(heap[parent(i)],heap[i]);
            i = parent(i);
        }
    }

    // moves the item at position i of array a
    // into its appropriate position
    void maxHeapify(int i){
        int left = leftChild(i);
        int right = rightChild(i);
        int largest = i;

        if(left <= heap.size() && heap[i] < heap[left]){
            largest = left;
        }
        if(right <= heap.size()  && heap[i] < heap[right]){
            largest = right;
        }
        if(largest != i){
            swap(heap[largest],heap[i]);
            maxHeapify(largest); // largest postion contents the smaller value after swap.
        }

    }

    // returns the  maximum item of the heap
    int getMax() {
        return heap[0];
    }

    // deletes the max item and return
    int extractMax() {
        int maxValue = heap[0];
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        maxHeapify(0);
        return maxValue;
    }

    // prints the heap
    void printHeap() {
       for(int i=0; i<heap.size();i++){
           cout<<heap[i]<<" ";
       }
       cout<<endl;
    }
};

int main() {
    BinaryHeap heap;
    heap.insert(10);
    heap.insert(3);
    heap.insert(4);
    heap.insert(6);
    int maxValue = heap.extractMax();
    cout <<"max value: " << maxValue << endl;
    cout << "get max: " << heap.getMax()<<endl;
    heap.printHeap();
    return 0;
}