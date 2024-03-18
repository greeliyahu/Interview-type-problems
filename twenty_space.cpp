// PROBLEM:
/*
    Implement a function to replace all spaces in a string with '%20'.
*/


// SOLUTION:

#include <iostream> // cout
#include <string> // string


void replace_spaces(std::string& str_)
{
    std::string twenty = "%20";
    for (size_t i = 0; str_[i] != '\0'; ++i)
    {
        if (' ' == str_[i])
        {
            str_.replace(i, 1, twenty);
        }
    }
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::string str1 = "a b c d";
    replace_spaces(str1);
    std::cout << str1 << std::endl;

    // test 2
    std::string str2 = "a b c d ";
    replace_spaces(str2);
    std::cout << str2 << std::endl;

    // test 3
    std::string str3 = "  a  b  c  d  ";
    replace_spaces(str3);
    std::cout << str3 << std::endl;

    // test 4
    std::string str4 = "";
    replace_spaces(str4);
    std::cout << str4 << std::endl;

    return 0;
}