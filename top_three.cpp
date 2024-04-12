// PROBLEM:
/*
    Given an array of integers with repeated numbers, find the three numbers that repeat the most times. 
    If two numbers appear the same number of times the output should include the one which comes first in the original array.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector
#include <unordered_map> // unordered_map
#include <queue> // priority_queue

std::vector<int> top_three(std::vector<int>& arr_)
{
    std::unordered_map<int, size_t> counts;
    for (int num : arr_)
    {
        ++counts[num];
    }

    std::priority_queue<std::pair<size_t, int>> high_scorers;
    for (auto count : counts)
    {
        high_scorers.push({count.second, count.first});
    }

    std::vector<int> ret;
    for (size_t i = 0; i < 3 && !high_scorers.empty(); ++i)
    {
        ret.push_back(high_scorers.top().second);
        high_scorers.pop();
    }
    
    return ret;
}


// SIMPLE TESTS:

void print_vec(std::vector<int>& vec_)
{
    size_t size = vec_.size();
    std::cout << "[";
    size_t i = 0;
    for (; i < size - 1; ++i)
    {
        std::cout << vec_[i] << ", ";
    }
    std::cout << vec_[i] << "]" << std::endl;
}

int main()
{
    // test 1
    std::vector<int> arr1 = {3, 4, 2, 3, 16, 3, 15, 16, 15, 15, 16, 2, 3};
    std::vector<int> ret1 = top_three(arr1);
    print_vec(ret1);
    
    std::cout << "All tests passed." << std::endl;
    
    return 0;
}