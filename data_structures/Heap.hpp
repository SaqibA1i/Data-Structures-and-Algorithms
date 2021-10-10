#include <iostream>
#include <vector>

class Heap {
    private:
        std::vector<int> heap;
    public:
    Heap(std::vector<int> nums){
        heap = nums;
        // build the heap
        build_heap();
    }

    int operator[](unsigned int index){
      return heap[index];
    }
      /* 
    heapify: Takes an index to ensure that the element at index
        'i' doesnt violate the heap property. If it does then it 
        moves it down the heap until it is satisfied.
    Running Time: O(logn)
    */
    void heapify(unsigned int i) {
      unsigned int heap_length = heap.size();
      unsigned int l = 2 * i + 1;
      unsigned int r = 2 * i + 2;
      unsigned int largest = i;
      if(l < heap_length && heap[largest] < heap[l]){
        largest = l;
      }
      if(r < heap_length && heap[largest] < heap[r]){
        largest = r;
      }
      if(largest != i){
        std::swap(heap[i],heap[largest]);
        heapify(largest);
      }
    }  

  /* 
    buildHeap: Makes an array into a heap, ensuring the heap 
        property is satisfied
    Running Time: O(nlogn) as the heapify function is essentially called n times
    */
   void build_heap(){
     for(int i =  heap.size()/2; i >=0;i--){
       heapify(i);
     }
   };

   /*
    add: Adds an element to the heap and re builds the heap to ensure the
        heap property is satisfied.
    Running Time: O(nlogn) 
    */
    void add(int number){
      heap.push_back(number);
      build_heap();
    }

    void remove(unsigned int index){
      std::swap(heap[index],heap[heap.size() - 1]);
      build_heap();
    }

    int remFirst(){
      int first = heap[0];
      remove(0);
      build_heap();
      return first;
    }

    void print(){
      for(int i =0;i < heap.size();i++){
        std::cout << heap[i] << ", ";
      }
    }

    unsigned int getLength(){
      return heap.size();
    }

    void swap(unsigned int index1, unsigned int index2){
      std::swap(heap[index1],heap[index2]);
    }

    void pop_back(){
      heap.pop_back();
    }
};