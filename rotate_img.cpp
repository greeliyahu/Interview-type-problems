// PROBLEM:
/*
    You are given an n x n matrix representing an image, rotate the image by 90 degrees clockwise in-place.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector
#include <algorithm> // reverse, swap

void rotate(std::vector<std::vector<int>>& matrix_)
{
    size_t size = matrix_.size();
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < i; ++j)
        {
            std::swap(matrix_[i][j], matrix_[j][i]);
        }
    }
    for (size_t i = 0; i < size; ++i)
    {
        std::reverse(matrix_[i].begin(), matrix_[i].end());
    }
}


// SMIPLE TESTS:

void print_grid(std::vector<std::vector<int>>& grid_)
{
    size_t rows = grid_.size();
    size_t cols = grid_[0].size();
    for (size_t i = 0; i < rows; ++i)
    {
        std::cout << "[";
        size_t j = 0;
        for (; j < cols - 1; ++j)
        {
            std::cout <<  grid_[i][j] << ", ";
        }
        std::cout <<  grid_[i][j] << "]" << std::endl;
    }
}

int main()
{
    // test 1
    std::vector<std::vector<int>> img1 = {{1, 2, 3},
                                          {4, 5, 6},
                                          {7, 8, 9}};
    rotate(img1);
    print_grid(img1);

    // test 2
    std::vector<std::vector<int>> img2 = {{5, 16, 9, 11},
                                          {14, 8, 4, 13},
                                          {10, 3, 17, 6},
                                          {12, 1, 2, 15}};
    rotate(img2);
    print_grid(img2);

    return 0;
}