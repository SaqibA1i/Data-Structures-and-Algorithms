#include <iostream>
#include "Heap.hpp"
#include "LinkedList.hpp"
#include "Stack.hpp"
#include "DoublyLinkedList.hpp"
#include "Graph.hpp"

#include <vector>

int main(){
    std::vector<int> sort_this = {9,7,8,3,1,2,78,18,-1};

    merge_sort(sort_this);
    for(int i = 0; i < sort_this.size();i++){
        std::cout<< sort_this[i]<<" , ";
    }
    std::cout<<"\n";
    return 0;
}