// PROBLEM:
/*  
    Given an integer array nums and an integer val, the number of elements in nums which are not equal to val is k.
    Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
    The remaining elements and the size of nums are not important. Return k.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector
#include <algorithm> // min

int remove_element(std::vector<int>& nums, int val)
{
    int k = 0;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != val)
        {
            nums[k] = nums[i];
            ++k;
        }
    }
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
    std::vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int ans1 = remove_element(nums1, val1);
    print_k_first(nums1, ans1);

    // test 2
    std::vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int ans2 = remove_element(nums2, val2);
    print_k_first(nums2, ans2);

    return 0;
}