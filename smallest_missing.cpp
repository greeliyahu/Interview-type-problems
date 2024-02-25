// PROBLEM:
/*
    Find the smallest positive integer that is missing from an array of integers.
*/


// SOLUTION:

#include <cassert> // assert
#include <iostream> // cout
#include <vector> // vector
#include <algorithm> // sort

int smallest_missing(std::vector<int>& nums_)
{
    size_t size = nums_.size();
    std::sort(nums_.begin(), nums_.end());
    int max = nums_[0] > 0 ? nums_[0] : 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (nums_[i] == max + 1)
        {
            ++max;
        }
    }
    return max + 1;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::vector<int> arr1 = {1, 0, 2};
    assert (3 == smallest_missing(arr1));

    // test 2
    std::vector<int> arr2 = {3, 1, 0, -1};
    assert (2 == smallest_missing(arr2));

    // test 3
    std::vector<int> arr3 = {7, 8, 9, 11, 12};
    assert (10 == smallest_missing(arr3));

    // test 4
    std::vector<int> arr4 = {7, 8, 9, 11, 10};
    assert (12 == smallest_missing(arr4));

    std::cout << "All tets passed." << std::endl;

    return 0;
}