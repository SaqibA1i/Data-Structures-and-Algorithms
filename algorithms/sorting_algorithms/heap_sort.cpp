std::vector<int> heap_sort(std::vector<int> nums){
    Heap newHeap(nums);
    std::vector<int> sorted = {};
    while (newHeap.getLength() != 0){
        sorted.push_back(newHeap[0]);
        newHeap.swap(0,newHeap.getLength() - 1);
        newHeap.pop_back();
        // Since we swapped the first largest element
        //  with the last one, the heap property is
        //  not satisfied.
        newHeap.heapify(0);
    }
    // reverse the vector to have order small to large
    for(int i = 0; i < sorted.size() / 2; i++){
        std::swap(sorted[i],sorted[sorted.size() - i - 1]);
    }
    return sorted;   
}

