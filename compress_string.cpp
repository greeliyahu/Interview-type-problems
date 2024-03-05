// PROBLEM:
/*
    Implement a method to perform basic string compression using the counts of repeated characters.
    For example, the string aabcccccaaa would become a2blc5a3.
    If the "compressed" string is not smaller than the original string, return the original string.
*/


// SOLUTION:

#include <iostream> // cout
#include <string> // string

std::string compress(std::string& str_)
{
    size_t size = str_.size() ? str_.size() : 1;
    std::string ret = "";
    size_t count = 1;
    for (size_t i = 0; i < size - 1; ++i)
    {
        while (i < size - 1 && str_[i] == str_[i+1])
        {
            ++count;
            ++i;
        }
        ret += str_[i];
        if (count > 1)
        {
            ret += std::to_string(count);
            count = 1;
        }
    }
    return ret.size() < size ? ret : str_;
}


// SMIPLE TESTS:

int main()
{
    // test 1
    std::string str1("aabcccccaaa");
    std::string cmp1 = compress(str1);
    std::cout << cmp1 << std::endl;

    // test 2
    std::string str2("abcdefg");
    std::string cmp2 = compress(str2);
    std::cout << cmp2 << std::endl;

    // test 3
    std::string str3("aabbccddeeffgg");
    std::string cmp3 = compress(str3);
    std::cout << cmp3 << std::endl;

    // test 4
    std::string str4("");
    std::string cmp4 = compress(str4);
    std::cout << cmp4 << std::endl;

    return 0;
}