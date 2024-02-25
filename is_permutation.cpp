// PROBLEM:
/*
    Write a function to test whether two strings are permutations of one another.
*/


// SOLUTION:

#include <iostream> // cout
#include <cassert> // assert
#include <string> // string

bool is_permutation(std::string& s1_, std::string& s2_)
{
    size_t lut1[128] = {0};
    size_t lut2[128] = {0};
    for (auto letter : s1_)
    {
        ++lut1[letter];
    }
    for (auto letter : s2_)
    {
        ++lut2[letter];
    }
    for (size_t i = 0; i < 128; ++i)
    {
        if (lut1[i] != lut2[i])
        {
            return false;
        }
    }
    return true;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::string s1 = "abcdefg";
    std::string s2 = "gbcafde";
    assert (true == is_permutation(s1, s2));

    // test 2
    std::string s3 = "";
    std::string s4 = "";
    assert (true == is_permutation(s3, s4));

    // test 3
    std::string s5 = "abcdefg";
    std::string s6 = "abfdetf";
    assert (false == is_permutation(s5, s6));

    std::cout << "All tests passed." << std::endl;

    return 0;
}