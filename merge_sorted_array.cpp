// PROBLEM:
/*  
    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
    Merge nums1 and nums2 into a single array sorted in non-decreasing order.
    The length of nums1 is m + n, with n zeroes at the end which serve as placeholders and should be overwritten.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector

void merge(std::vector<int>& nums1_, int m_, std::vector<int>& nums2_, int n_)
{
    int idx1 = m_ - 1;
    int idx2 =  n_ - 1;;
    int idx_merged = m_ + n_ - 1;

    while (idx1 >= 0 && idx2 >= 0)
    {
        if (nums1_[idx1] > nums2_[idx2])
        {
            nums1_[idx_merged--] = nums1_[idx1--];
        }
        else
        {
            nums1_[idx_merged--] = nums2_[idx2--];
        }
    }
    while (idx2 >= 0)
    {
        nums1_[idx_merged--] = nums2_[idx2--];
    }
}


// SIMPLE TESTS:

void print_vector(std::vector<int>& vec_)
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
    std::vector<int>nums1 = {2, 5, 7, 0, 0, 0, 0};
    std::vector<int>nums2 = {3, 5, 6, 9};
    int size1 = 3;
    int size2 = 4;
    merge(nums1, size1, nums2, size2);
    print_vector(nums1);

    // test 2
    std::vector<int>nums3 = {1};
    std::vector<int>nums4 = {};
    int size3 = 1;
    int size4 = 0;
    merge(nums3, size3, nums4, size4);
    print_vector(nums3);

    // test 3
    std::vector<int>nums5 = {0};
    std::vector<int>nums6 = {1};
    int size5 = 0;
    int size6 = 1;
    merge(nums5, size5, nums6, size6);
    print_vector(nums5);
    
    return 0;
}