// PROBLEM:
/*  
    Given an array of integers of size n, return the majority element.
    The majority element is the element that appears more than n/2 times.
    The majority element always exists in the array.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector

 int majority_element(std::vector<int>& nums_)
    {
        int count = 0;
        int maj = 0;
        
        for (int num : nums_)
        {
            if (count == 0)
            {
                maj = num;
            }
            if (num == maj)
            {
                ++count;
            }
            else
            {
                --count;
            }
        }
        return maj;
    }

// SIMPLE TESTS:

int main()
{
    // test 1
    std::vector<int>nums1 = {2, 3, 1, 1, 4};
    std::cout << majority_element(nums1) << std::endl;

    // test 2
    std::vector<int>nums2 = {3, 3, 2, 2, 2, 3, 3};
    std::cout << majority_element(nums2) << std::endl;

    return 0;
}