// PROBLEM:
/*
    Given an integer width_ describing the width of a river, the river can be crossed only when all spots from 1 to width_ are filled.
    An array of integers rocks_ represents rocks falling into the river, rocks_[i] represents the spot where a rock falls at time i.
    Write a function that calculates earliest time when the river can be crossed.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector
#include <cassert> // assert

int cross(int width_, std::vector<int> &rocks_)
{
    int size = rocks_.size();
    if (width_ > size)
    {
        return -1;
    }
    std::vector<char> counts(width_+1, 0);
    int left = width_;
    int i = 0;
    while ((i < size) && left)
    {
        if (0 == counts[rocks_[i]])
        {
            ++counts[rocks_[i]];
            --left;
        }
        ++i;
    }
    return left ? -1 : --i;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    int target1 = 5;
    std::vector<int> arr1 = {1, 3, 1, 4, 2, 3, 5, 4};
    int res1 = cross(target1, arr1);
    assert(6 == res1);

    // test 2
    int target2 = 6;
    std::vector<int> arr2 = {1, 3, 1, 4, 2, 3, 5, 4};
    int res2 = cross(target2, arr2);
    assert(-1 == res2);

    // test 3
    int target3 = 9;
    std::vector<int> arr3 = {1, 3, 7, 4, 2, 6, 5, 9};
    int res3 = cross(target3, arr3);
    assert(-1 == res3);

    // test 4
    int target4 = 5;
    std::vector<int> arr4 = {1, 3, 4, 5, 1, 3, 5, 4, 2};
    int res4 = cross(target4, arr4);
    assert(8 == res4);

    std::cout << "All tests passed." << std::endl;

    return 0;
}