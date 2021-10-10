void insertion_sort(std::vector<int> &nums){
    // for loop iterates over each entry with a
    //     nested while loop that places the entry
    //      at that index at the correct location
    for(int i = 1 ; i < nums.size(); i++){
        unsigned int j = i;
        while(j > 0 && nums[j - 1]> nums[j] ){
            std::swap(nums[j-1],nums[j]);
            --j;
        }
    }
}