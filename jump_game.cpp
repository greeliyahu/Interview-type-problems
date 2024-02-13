// PROBLEM:
/*  
    Each element in an integer array represents your maximum jump length from that position.
    Return true if you can reach the last index beginning jumping from the first index, or false otherwise.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector

bool can_jump(std::vector<int>& nums_)
{
    bool ret = true;
    int target = nums_.size() - 1;
    for (int i = target; i > -1; --i)
    {
        ret = false;
        if (nums_[i] >= target - i)
        {
            ret = true;
            target = i;
        }
    }
    return ret;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::vector<int>nums1 = {2, 3, 1, 1, 4};
    std::cout << can_jump(nums1) << std::endl;

    // test 2
    std::vector<int>nums2 = {3, 2, 1, 0, 4};
    std::cout << can_jump(nums2) << std::endl;

    return 0;
}