// PROBLEM:
/*
    Implement a function which determines if all characters in a string are unique.
    Solve with and without additional data structures.
*/


// SOLUTION:

#include <iostream> // cout
#include <cassert> // assert
#include <string> // string
#include <algorithm> // sort

bool all_unique1(std::string& str_)
{
    char lut[128] = {0};
    for (auto letter : str_)
    {
        if (++lut[letter] != 1)
        {
            return false;
        }
    }
    return true;
}

bool all_unique2(std::string& str_)
{
    size_t size = str_.size();
    if (size)
    {
        for (size_t i = 0; i < size - 1; ++i)
        {
            for (size_t j = i + 1; j < size; ++j)
            {
                if (str_[i] == str_[j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool all_unique3(std::string str_)
{
    size_t size = str_.size();
    if (size)
    {
        std::sort(str_.begin(), str_.end());
        for (size_t i = 0; i < size - 1; ++i)
        {
            if (str_[i] == str_[i+1])
            {
                return false;
            }
        }
    }
    return true;
}



// SIMPLE TESTS:

int main()
{
    // test 1
    std::string s1 = "abcdefg";
    assert (true == all_unique1(s1));
    assert (true == all_unique2(s1));
    assert (true == all_unique3(s1));


    // test 2
    std::string s2 = "abcdefa";
    assert (false == all_unique1(s2));
    assert (false == all_unique2(s2));
    assert (false == all_unique3(s2));


    // test 3
    std::string s3 = "";
    assert (true == all_unique1(s3));
    assert (true == all_unique2(s3));
    assert (true == all_unique3(s3));


    std::cout << "All tests passed." << std::endl;

    return 0;
}