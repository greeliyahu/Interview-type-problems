// PROBLEM:
/*
    Given an array of positive integers and a positive integer target, return the minimal length of a
    subarray whose sum is greater than or equal to target. If there is no such subarray, return 0.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector
#include <climits> // INT_MAX

int min_subarray_len(std::vector<int>& nums_, int target_)
{
    int arr_sum = 0;
    int ret = INT_MAX;
    int size = nums_.size();
    int left = 0;
    for (int right = 0; right < size; ++right)
    {
        arr_sum += nums_[right];
        while (arr_sum >= target_)
        {
            arr_sum -= nums_[left];
            ret = std::min(ret, right - left + 1);
            ++left;
        }
    }
    return ret == INT_MAX ? 0 : ret;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::vector<int> nums1 = {12, 5, 4, 3, 12, 10};
    int target1 = 22;
    std::cout << min_subarray_len(nums1, target1) << std::endl;

    // test 2
    std::vector<int> nums2 = {7, 13, 13};
    int target2 = 13;
    std::cout << min_subarray_len(nums2, target2) << std::endl;

    // test 3
    std::vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    int target3 = 9;
    std::cout << min_subarray_len(nums3, target3) << std::endl;

    return 0;
}