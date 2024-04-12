// PROBLEM:
/*
    In a non-empty integer array nums of size N, a pair of integers (P, Q), such that 0 <= P < Q < N, is called a slice.
    The average of a slice (P, Q) is (nums[P] + nums[P + 1] + ... + nums[Q]) / (Q - P + 1).
    Find the starting position of a slice whose average is minimal.
    If there is more than one slice with a minimal average, return the smallest starting position of such a slice.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> //vector
#include <cassert> // assert

int min_slice(std::vector<int>& nums_)
{
    int size = nums_.size();
    double min_avg = (nums_[0] + nums_[1]) / 2.0;
    int ret = 0;

    for (int i = 0; i < size - 1; ++i)
    {
        double avg = (nums_[i] + nums_[i + 1]) / 2.0;
        if (avg < min_avg)
        {
            min_avg = avg;
            ret = i;
        }
    }

    for (int i = 0; i < size - 2; ++i)
    {
        double avg = (nums_[i] + nums_[i + 1] + nums_[i + 2]) / 3.0;
        if (avg < min_avg)
        {
            min_avg = avg;
            ret = i;
        }
    }

    return ret;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::vector<int> arr1 = {4, 2, 2, 5, 1, 5, 8};
    assert(1 == min_slice(arr1));

    // test 2
    std::vector<int> arr2 = {4, 12, 2, 5, 1, 5, 8};
    assert(2 == min_slice(arr2));

    // test 3
    std::vector<int> arr3 = {4, 12, 2, -5, 1, 5, 8};
    assert(3 == min_slice(arr3));


    std::cout << "All tests passed." << std::endl;
    return 0;
}