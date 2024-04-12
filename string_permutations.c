// PROBLEM:
/*
    Write a function that prints all the permutations of a given string.
*/


// SOLUTION:

#include <stdio.h>
#include <string.h>

void swap(char *x_, char *y_)
{
    char temp = *x_;
    *x_ = *y_;
    *y_ = temp;
}

void permutate(char *str_, size_t left_, size_t right_)
{
    if (left_ == right_)
    {
        printf("%s\n", str_);
    }
    for (size_t i = left_; i <= right_; ++i)
    {
        swap(str_ + left_, str_ + i);
        permutate(str_, left_ + 1, right_);
        swap(str_ + left_, str_ + i);
    }
}

void print_permutations(char* str_)
{
    if (!str_)
    {
        return;
    }
    permutate(str_, 0, strlen(str_) - 1);
}



// SIMPLE TESTS:

int main()
{
    // test 1
    char str1[] = "ABC";
    print_permutations(str1);
    
    // test 2
    char str2[] = "A";
    print_permutations(str2);

    // test 3
    char *str3 = NULL;
    print_permutations(str3);

    // test 4
    char str4[] = "BBB";
    print_permutations(str4);

    // test 5
    char str5[] = "ABCD";
    print_permutations(str5);
    
    puts("All tests passed.");

    return 0;
}