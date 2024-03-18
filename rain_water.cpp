// PROBLEM:
/*
    Given an array of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/


// SOLUTION:

#include <cassert> // assert
#include <vector> // vector
#include <iostream> // cout
#include <climits> // INT_MIN


int trap_water(std::vector<int>& topo_)
{
    int left = 0;
    int right = topo_.size() - 1;
    int max_l = INT_MIN;
    int max_r = INT_MIN;
    int ret = 0;

    while (left < right)
    {
        max_l = std::max(max_l, topo_[left]);
        max_r = std::max(max_r, topo_[right]);
        ret += (max_l < max_r) ? max_l - topo_[left++] : max_r - topo_[right--];
    }

    return ret;
}


// SIMPLE TESTS

int main()
{
    // test 1
    std::vector<int> topo1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    assert(6 == trap_water(topo1));

    // test 2
    std::vector<int> topo2 = {4,2,0,3,2,5};
    assert(9 == trap_water(topo2));

    // test 3
    std::vector<int> topo3 = {};
    assert(0 == trap_water(topo3));

    // test 4
    std::vector<int> topo4 = {0, 1, 2, 3, 4, 5, 6};
    assert(0 == trap_water(topo4));

    // test 5
    std::vector<int> topo5 = {6, 5, 4, 3, 2, 1, 0};
    assert(0 == trap_water(topo5));

    std::cout << "All tests passed." << std::endl;

    return 0;
}