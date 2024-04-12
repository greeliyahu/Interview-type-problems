// PROBLEM:
/*
    Given an array nums of length n and a number x, check whether there are two elements in nums whose sum is exactly x.
    Return the indices of those elements if they exist.
*/


// SOLUTION:

#include <iostream> // cout
#include <unordered_map> // unordered_map

std::pair<int, int> two_sum(int nums_[], int n_, int x_)
{
    std::unordered_map<int, int> map;
    for(int i = 0; i < n_; ++i)
    {
        auto const found = map.find(x_ - nums_[i]);
        if (map.end() == found)
        {
            map.emplace(nums_[i], i);
        }
        else
        {
            return std::make_pair(i, found->second);
        }
    }
    return std::make_pair(-1, -1);
}


// SIMPLE TESTS:

int main()
{
    // test 1
    int arr1[] = {0, -1, 2, -3, 1};
    int x1 = -2;
    std::cout << two_sum(arr1, 5, x1).first << ", " << two_sum(arr1, 5, x1).second << std::endl;

    // test 2
    int arr2[] = {1, -2, 1, 0, 5};
    int x2 = 0;
    std::cout << two_sum(arr2, 5, x2).first << ", " << two_sum(arr2, 5, x2).second << std::endl;

    // test 3
    int arr3[] = {0};
    int x3 = 0;
    std::cout << two_sum(arr3, 1, x3).first << ", " << two_sum(arr3, 1, x3).second << std::endl;

    return 0;
}