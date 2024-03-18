// PROBLEM:
/*
    An array of integers represents how good kids have been this year (the higher  - the better).

    Santa is giving presents to these kids according to those rules:
        - Each kid gets at least one present.
        - Kids who have been better than their neighbors get more presents.

    Return the minimum number of presents needed to satisfy these rules.
*/


// SOLUTION:

#include <iostream> // cout, size_t
#include <cassert> // assert
#include <vector> // vector

int min_presents(std::vector<int>& ratings_)
{
    int size = ratings_.size();
    int presents = size;
    int i = 1;
    while (i < size)
    {
        if(ratings_[i] == ratings_[i-1])
        {
            ++i;
            continue;
        }
        
        int up = 0;
        while (ratings_[i] > ratings_ [i-1])
        {
            ++up;
            presents += up;
            ++i;
            if (i == size)
            {
                return presents;
            }
        }
        
        int down = 0;
        while (i < size && ratings_[i] < ratings_[i-1])
        {
            ++down;
            presents += down;
            ++i;
        }
        
        presents -= std::min(up, down);
    }
    return presents;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::vector<int> vec1 = {1, 3, 2, 2, 1};
    assert (7 == min_candy(vec1));

    // test 2
    std::vector<int> vec2 = {1, 2, 87, 87, 87, 2, 1};
    assert (13 == min_candy(vec2));

    // test 3
    std::vector<int> vec3 = {1, 2, 87, 88, 87, 2, 1};
    assert (16 == min_candy(vec3));

    // test 4
    std::vector<int> vec4 = {1, 2, 87, 88, 87, 2};
    assert (13 == min_candy(vec4));

    // test 5
    std::vector<int> vec5 = {};
    assert (0 == min_candy(vec5));

    std::cout << "All tests passed." << std::endl;

    return 0;
}