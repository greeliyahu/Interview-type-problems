// PROBLEM:
/*  
    Given an array of unique integers which is almost sorted, i.e. element arr[i] can may be swapped with arr[i+1] or arr[i-1].
    Write a function that returns the index of an element in this array (or -1 if not found).
*/


// SOLUTION:

#include <stdio.h> // printf, puts
#include <assert.h> // assert

int find_almost_sorted(int arr_[], int size_, int key_)
{
    assert(0 < size_);
    int min = 0;
    int max = size_;
    while (max >= min)
    {
        int mid = min + (max - min) / 2;

        if (key_ == arr_[mid] )
        {
            return mid;
        }
        else if ((mid < size_-1) && key_ == arr_[mid+1])
        {
            return mid + 1;
        }
        else if ((mid > 0) && key_ == arr_[mid-1])
        {
            return mid - 1;
        }
		else if (arr_[mid] < key_)
		{
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
    }
    return -1;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    int arr1[7] = {10, 3, 40, 20, 50, 80, 70};
    int key1 = 40;
    assert (2 == find_almost_sorted(arr1, 7, key1));

    // test 2
    int arr2[7] = {10, 3, 40, 20, 50, 80, 70};
    int key2 = 90;
    assert (-1 == find_almost_sorted(arr2, 7, key2));

    // test 3
    int arr3[8] = {0, 2, 1, 4, 3, 5, 7, 6};
    int key3 = 0;
    assert (0 == find_almost_sorted(arr3, 8, key3));

    // test 4
    int arr4[8] = {1, 0, 3, 2, 5, 4, 6, 7};
    int key4 = 7;
    assert (7 == find_almost_sorted(arr4, 8, key4));
    
    // test 5
    int arr5[3] = {1, 3, 2};
    int key5 = 4;
    assert (-1 == find_almost_sorted(arr5, 3, key5));

    // test 6
    int arr6[3] = {1, 3, 2};
    int key6 = 0;
    assert (-1 == find_almost_sorted(arr6, 3, key6));

    
    puts("All tests passed.");
    
    return 0;
}