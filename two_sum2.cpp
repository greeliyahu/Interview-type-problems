// PROBLEM:
/*
    Given an array of integers and a number x, check whether there are two elements in the array whose sum is exactly x.
    If so, print the pair.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector
#include <unordered_map> // unordered_map

void two_sum2(std::vector<int>& nums_, int x_)
{
    std::unordered_map<int, int> map;
    for (int num : nums_)
    {
        auto const found = map.find(x_ - num);
        if (map.end() == found)
        {
            map.emplace(num, num);
        }
        else
        {
            std::cout << "A pair with the given sum " << x_ << " is: " << num << ", " << found->second << std::endl;
            return;
        }
    }
    std::cout << "A pair with the given sum " << x_ << " does not exist." << std::endl;;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::vector<int> arr1 = {0, -1, 2, -3, 1};
    int x1 = -2;
    two_sum2(arr1, x1);

    // test 2
    std::vector<int> arr2 = {1, -2, 1, 0, 5};
    int x2 = 0;
    two_sum2(arr2, x2);

    // test 3
    std::vector<int> arr3 = {0};
    int x3 = 5;
    two_sum2(arr3, x3);

    // test 4
    std::vector<int> arr4 = {-1, 4, 76, 0, -42, 8, 9};
    int x4 = 7;
    two_sum2(arr4, x4);

    return 0;
}