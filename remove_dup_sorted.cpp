// PROBLEM:
/*  
    Given an integer array sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
    The relative order of the elements must not change.
    Return the number of unique elements in the array.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector

size_t remove_duplicates(std::vector<int>& nums)
{
    size_t k = 0;
    for (size_t i = 0; i < nums.size()-1; ++i)    
    {
        if (nums[i] != nums[i+1])
        {
            nums[k] = nums[i];
            ++k;
        }
    }
    nums[k] = nums[nums.size()-1];
    ++k;
    return k;
}


// SIMPLE TESTS:

void print_k_first(std::vector<int>& vec_, size_t k_)
{
    size_t size = std::min(vec_.size(), k_);
    std::cout << "[";
    size_t i = 0;
    for (; i < size - 1; ++i)
    {
        std::cout << vec_[i] << ", ";
    }
    std::cout << vec_[i] << "]" << std::endl;
}

int main()
{
    // test 1
    std::vector<int> nums1 = {1, 2, 2, 2, 3};
    size_t ans1 = remove_duplicates(nums1);
    print_k_first(nums1, ans1);

    // test 2
    std::vector<int> nums2 = {0, 0, 0, 1, 2, 2, 3, 4, 4, 5};
    size_t ans2 = remove_duplicates(nums2);
    print_k_first(nums2, ans2);

    // test 3
    std::vector<int> nums3 = {0, 1, 2, 2, 3, 3, 4, 4};
    size_t ans3 = remove_duplicates(nums3);
    print_k_first(nums3, ans3);

    return 0;
}