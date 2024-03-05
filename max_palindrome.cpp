// PROBLEM:
/*
    Write a function that receives a string and returns the length of the longest palindrome substring in it.
*/


// SOLUTION:

#include <iostream> // cout
#include <cassert> // assert
#include <string> // string

int expand(std::string& str_, int left_, int right_)
{
    while (left_ >= 0 && right_ < str_.size() && str_[left_] == str_[right_])
    {
        --left_;
        ++right_;
    }
    return right_ - left_ - 1;
};

int max_palindrome(std::string& str_)
{
    int size = str_.size();
    int max = 0;
    if (size)
    {
        for (int i = 0; i < size - 1; ++i)
        {
            int odd = expand(str_, i, i);
            int even = expand(str_, i, i + 1);
            if (odd > max)
            {
                max = odd;
            }
            if (even > max)
            {
                max = even;
            }
        }
    }
    return max;
}


// SMIPLE TESTS:

int main()
{
    // test 1
    std::string str1("aabcccccaaa");
    std::cout << max_palindrome(str1) << std::endl;
    assert(5 == max_palindrome(str1));

    // test 2
    std::string str2("abcdefg");
    assert(1 == max_palindrome(str2));

    // test 3
    std::string str3("abcdefedckj");
    assert (7 ==  max_palindrome(str3));

    // test 4
    std::string str4 = "";
    assert (0 == max_palindrome(str4));

 
    std::cout << "All tests passed." << std::endl;
    return 0;
}