// PROBLEM:
/*
    Given an array of integers, find the most frequent element in it.
    If there are multiple such elements, return any one of them.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector
#include <unordered_map> // unordered_map

int most_frequent(std::vector<int>& nums_)
{
    std::unordered_map<int, size_t> map;
    int max;
    size_t max_count = 0;
    for (int num : nums_)
    {
        auto const found = map.find(num);
        if (map.end() == found)
        {
            map[num] = 1;
        }
        else
        {
            ++map[num];
        }
        if (map[num] > max_count)
        {
            max = num;
            max_count = map[num];
        }
    }
    return max;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::vector<int>nums1 = {2, 3, 1, 1, 4};
    std::cout << most_frequent(nums1) << std::endl;

    // test 2
    std::vector<int>nums2 = {3, 3, 2, 2, 2, 3, 3};
    std::cout << most_frequent(nums2) << std::endl;

    // test 3
    std::vector<int>nums3 = {3, 3, 3, 2, 1, 5};
    std::cout << most_frequent(nums3) << std::endl;

    return 0;
}