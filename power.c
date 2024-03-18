// PROBLEM:
/*  
    Write an efficient function to calculate a power of two unsigned integers. Ignore overflow.
*/


// SOLUTION:

#include <stdio.h> // printf, puts
#include <assert.h> // assert

unsigned int power(unsigned int base_, unsigned int exp_)
{
    unsigned int temp = base_;
    unsigned int ret = 1;
    while (exp_)
    {
        if (exp_ & 1)
        {
            ret *= temp;
        }
        temp *= temp;
        exp_ >>= 1;
    }
    return ret;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    assert (8 == power(2, 3));

    // test 2
    assert (1 == power(5, 0));

    // test 3
    assert (625 == power(5, 4));

    // test 4
    assert (1220703125 == power(5, 13));

    // test 5
    assert (1000000000 == power(10, 9));

    puts("All tests passed.");
    
    return 0;
}