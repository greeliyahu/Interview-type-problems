// PROBLEM:
/*
    Given an array, print the Next Greater Element for every element.
    The Next greater Element for an element x is the first greater element on the right side of x in the array.
    Elements for which no greater element exists, consider the next greater element as -1.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector
#include <stack> // stack

void print_vector(std::vector<int>& vec_)
{
    std::cout << "[";
    for (int num : vec_)
    {
        std::cout << num << ", ";
    }
    std::cout << "]\n";
}

void next_greater_elements(std::vector<int>& vec_)
{
    size_t size = vec_.size();
    if (!size)
    {
        return;
    }
    std::vector<int> ans(size, -1);
    std::stack<size_t> stack;
    
    stack.push(0);
    for (size_t i = 1; i < size; ++i)
    {
        while (!stack.empty() && vec_[i] > vec_[stack.top()])
        {
            ans[stack.top()] = vec_[i];
            stack.pop();
        }
        stack.push(i);
    }
    print_vector(ans);
}


// SMIPLE TESTS:

int main()
{
    // test 1
    std::vector<int> arr1 = {1, 2, 3, 4 ,5, 6};
    next_greater_elements(arr1);
    
    // test 2
    std::vector<int> arr2 = {4, 5, 2, 25};
    next_greater_elements(arr2);

    // test 3
    std::vector<int> arr3 = {10, 4, 5, 2, 25};
    next_greater_elements(arr3);

    // test 4
    std::vector<int> arr4 = {10, 4, 3, 2, 1};
    next_greater_elements(arr4);

    // test 5
    std::vector<int> arr5 = {};
    next_greater_elements(arr5);


    std::cout << "All tests passed." << std::endl;

    return 0;
}