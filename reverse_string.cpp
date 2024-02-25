// PROBLEM:
/*
    Implement a function which reverses a null-terminated string.
*/


// SOLUTION:

#include <iostream> // cout
#include <cassert> // assert
#include <string> // string

void reverse(std::string& str_)
{
    size_t end = str_.size();
    if (!end)
    {
        return;
    }
    --end;
    size_t start = 0;
    while (start < end)
    {
        std::swap(str_[start], str_[end]);
        ++start;
        --end;
    }
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::string s1 = "abcdefg";
    reverse(s1);
    assert (s1 == "gfedcba");

    // test 2
    std::string s2 = "abcdef";
    reverse(s2);
    assert (s2 == "fedcba");

    // test 3
    std::string s3 = "a";
    reverse(s3);
    assert (s3 == "a");

    // test 4
    std::string s4("");
    reverse(s4);
    assert (s4 == "");

    std::cout << "All tests passed." << std::endl;

    return 0;
}