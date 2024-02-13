// PROBLEM:
/*
    Given a 2D matrix, return all elements of the matrix in spiral order.
    Example: 
    Input:  {{1,    2,   3},
             {4,    5,   6},
             {7,    8,   9}}
    Output: 1 2 3 4 6 9 8 7 4 5
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector

std::vector<int> spiral_order(std::vector<std::vector<int>>& matrix_)
{
    std::vector<int> ret;
    int min_row = 0;
    int max_row = matrix_.size() -1;
    int min_col = 0;
    int max_col =  matrix_[0].size() -1;

    while (min_col <= max_col && min_row <= max_row)
    { 
        for(int i = min_col ; i <= max_col; ++i)
        {
            ret.push_back(matrix_[min_row][i]);
        }
        ++min_row;
        if (min_col > max_col || min_row > max_row)
        {
            break;
        }

        for(int j = min_row ; j <= max_row; ++j)
        {
            ret.push_back(matrix_[j][max_col]);
        }
        --max_col;
        if (min_col > max_col || min_row > max_row)
        {
            break;
        }

        for(int i = max_col ; i >= min_col; --i)
        {
            ret.push_back(matrix_[max_row][i]);
        }
        --max_row;
        if (min_col > max_col || min_row > max_row)
        {
            break;
        }

        for(int j = max_row ; j >= min_row; --j)
        {
            ret.push_back(matrix_[j][min_col]);
        }
        ++min_col;
        if (min_col > max_col || min_row > max_row)
        {
            break;
        }
    }    
    return ret;
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
    //  test 1
    std::vector<std::vector<int>> mat1 = {{1,   2,   3,  4},
                                          {5,   6,   7,  8},
                                          {9,  10,  11, 12},
                                          {13, 14,  15, 16}};
    std::vector<int> spiral1 = spiral_order(mat1);
    print_vector(spiral1);

    // test 2
    std::vector<std::vector<int>> mat2 = {{1,  2,  3,   4,  5,  6},
                                          {7,  8,  9,  10, 11, 12},
                                          {13, 14, 15, 16, 17, 18}};
    std::vector<int> spiral2 = spiral_order(mat2);
    print_vector(spiral2);

    return 0;
}