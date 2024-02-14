// PROBLEM:
/*
    Given an array prices where prices[i] is the price of a given stock on the ith day, return the maximum profit you can achieve or 0 if none.
*/


// SOLUTION:

#include <iostream> // cout
#include <cassert> // assert
#include <vector> // vector

int max_profit(std::vector<int>& prices_)
{
    int buy = prices_[0];
    int sell = prices_[0];
    int profit = 0;

    for (size_t i = 1; i < prices_.size(); ++i)
    {
        if (prices_[i] - buy > profit)
        {
            sell = prices_[i];
            profit = sell - buy;
        }
        else if (prices_[i] < buy)
        {
            buy = prices_[i];
        }
    }
    return profit;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    assert(5 == max_profit(prices1));

    // test 2
    std::vector<int> prices2 = {7, 6, 4, 3, 1};
    assert(0 == max_profit(prices2));
    
    // test 3
    std::vector<int> prices3 = {7, 6, 11, 0, 8};
    assert(8 == max_profit(prices3));

    std::cout << "All tests passed." << std::endl;

    return 0;
}