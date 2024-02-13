// PROBLEM:
/*  
    Each element in an integer array of size n represents your maximum jump length from that position.
    Return the minimum number of jumps to reach nums[n - 1]. You can always reach nums[n - 1].
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector

int jump(std::vector<int>& nums_)
{ 
    int size = nums_.size();
    for (int i = 1; i < size; ++i)
    {
        nums_[i] = std::max(nums_[i] + i, nums_[i-1]);
    }
    int idx = 0;
    int ret = 0;
    while (idx < size - 1)
    {
        ++ret;
        idx = nums_[idx];
    }
    return ret;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::vector<int>nums1 = {2, 3, 1, 1, 4};
    std::cout << jump(nums1) << std::endl;

    // test 2
    std::vector<int>nums2 = {3, 2, 0, 1, 4};
    std::cout << jump(nums2) << std::endl;

    return 0;
}