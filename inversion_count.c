// PROBLEM:
/*
    Inversion Count for an array indicates how far (or close) the array is from being sorted.
    If the array is already sorted, then the inversion count is 0, but if the array is sorted in the reverse order, the inversion count is the maximum.
    Write a function that receives an array of integers and its size and returns the number of inversions.
*/


// SOLUTION:

#include <assert.h> // assert
#include <stdio.h> // puts
#include <stdbool.h> // bool

void swap(int *ptr1_, int *ptr2_)
{
	int temp = 0;
	temp = *ptr1_;
	*ptr1_ = *ptr2_;
	*ptr2_ = temp;
}

int inversion_count(int *array_, size_t size_)
{
    int ret = 0;
	for (size_t i = 0 ; i < size_ - 1; ++i)
	{
		bool swapped = false;
		for (size_t j = 0 ;j < size_ - i - 1; ++j)
		{
			if (array_[j] > array_[j+1])
			{
				swap((array_ + j), (array_ + j + 1));
				swapped = true;
                ++ret;
			}
		}
		if (0 == swapped)
		{
			break;
		}
	}
    return ret;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    int arr1[] = {8, 4, 2, 1};
    assert(6 == inversion_count(arr1, 4));

    // test 2
    int arr2[] = {3, 1, 2};
    assert(2 == inversion_count(arr2, 3));

    puts("All tests passed.");
    
    return 0;
}