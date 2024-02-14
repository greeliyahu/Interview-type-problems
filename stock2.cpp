// PROBLEM:
/*
    Given an array prices where prices[i] is the price of a given stock on the ith day, find and return the maximum profit you can achieve.
    On each day, you may buy and/or sell the stock and so accumulate profit.
*/


// SOLUTION:

#include <iostream> // cout
#include <cassert> // assert
#include <vector> // vector

int max_profit(std::vector<int>& prices_)
{
    int profit = 0;
    int temp_profit = 0;
    int buy = 0;
    for (size_t i = 1; i < prices_.size(); ++i) 
    {
        if (prices_[i] < prices_[i-1])
        {
            profit += temp_profit;
            temp_profit = 0;
            buy = i;
        }
        else
        {
            temp_profit = prices_[i] - prices_[buy];
        }
    }
    profit += temp_profit;
    return profit;
}

// SIMPLE TESTS:

int main()
{
    // test 1
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    assert(7 == max_profit(prices1));

    // test 2
    std::vector<int> prices2 = {1, 2, 3, 4, 5};
    assert(4 == max_profit(prices2));

    // test 3
    std::vector<int> prices3 = {7, 6, 5, 4, 3, 2, 1};
    assert(0 == max_profit(prices3));

    std::cout << "All tests passed." << std::endl;

    return 0;
}
