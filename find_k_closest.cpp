// PROBLEM:
/*
    Given a sorted array of integers and two values X and K, find the K closest numbers to X in the array. 
    If X is present in the array it should not be returned, only the other closest numbers are required.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector

std::vector<int> find_k_closest(std::vector<int>& arr_, int X_, int K_)
{    
    int size = arr_.size();
    int start = 0;
    int end = size - 1;
    int mid = (end - start) / 2;
    
    while (start <= end)
    {
        if (arr_[mid] == X_ || (arr_[mid-1] < X_ && arr_[mid+1] > X_))
        {
            break;
        }
        else if (arr_[mid] > X_)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    std::vector<int> ret;
    if (arr_[mid] != X_)
    {
        ret.push_back(arr_[mid]);
    }

    int forward = mid + 1;
    int backward = mid - 1;
    while (K_ > ret.size())
    {
        if ((forward + 1 < size) && ((arr_[forward] - X_) < (X_ - arr_[backward])))
        {
            ret.push_back(arr_[forward++]);
 
        }
        else if (backward - 1 > -1)
        {
            ret.push_back(arr_[backward--]);
        }
    }
    return ret;
}


// SIMPLE TESTS:

void print_vec(std::vector<int>& vec_)
{
    size_t size = vec_.size();
    std::cout << "[";
    size_t i = 0;
    for (; i < size - 1; ++i)
    {
        std::cout << vec_[i] << ", ";
    }
    std::cout << vec_[i] << "]" << std::endl;
}

int main()
{
    // test 1
    std::vector<int> arr1 = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int X1 = 35, K1 = 4;
    std::vector<int> ret1 = find_k_closest(arr1, X1, K1);
    print_vec(ret1);

    // test 2
    std::vector<int> arr2 = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int X2 = 41, K2 = 5;
    std::vector<int> ret2 = find_k_closest(arr2, X2, K2);
    print_vec(ret2);


    std::cout << "All tests passed." << std::endl;
    
    return 0;
}