// PROBLEM:
/*
    Given a matrix mat[n][n], find a submatrix sub[m][m] (m <= n, m >= 2) with the maximum possible sum of the elements in it.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector
#include <climits> // INT_MIN

std::vector<std::vector<int>> max_submatrix(std::vector<std::vector<int>>& matrix, int m)
{
    int size = matrix.size();
    std::vector<std::vector<int>> sums(size, std::vector<int>(size, 0));

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            sums[i][j] = matrix[i][j];
            if (i > 0)
            {
                sums[i][j] += sums[i - 1][j];
            }
            if (j > 0)
            {
                sums[i][j] += sums[i][j - 1];
            }
            if (i > 0 && j > 0)
            {
                sums[i][j] -= sums[i - 1][j - 1];
            }
        }
    }

    int max_sum = INT_MIN;
    std::vector<std::vector<int>> max_submatrix;

    for (int i = m - 1; i < size; ++i)
    {
        for (int j = m - 1; j < size; ++j)
        {
            int submatrix_sum = sums[i][j];
            if (i >= m)
            {
                submatrix_sum -= sums[i - m][j];
            }
            if (j >= m)
            {
                submatrix_sum -= sums[i][j - m];
            }
            if (i >= m && j >= m)
            {
                submatrix_sum += sums[i - m][j - m];
            }
            if (submatrix_sum > max_sum)
            {
                max_sum = submatrix_sum;
                max_submatrix.clear();
                for (int row = i - m + 1; row <= i; ++row)
                {
                    std::vector<int> row_sum;
                    for (int col = j - m + 1; col <= j; ++col)
                    {
                        row_sum.push_back(matrix[row][col]);
                    }
                    max_submatrix.push_back(row_sum);
                }
            }
        }
    }
    return max_submatrix;
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
    std::vector<std::vector<int>> matrix1 = {{1, 1, 1, 1, 1},
                                            {2, 2, 2, 2, 2},
                                            {3, 8, 6, 7, 3},
                                            {4, 4, 4, 4, 4},
                                            {5, 5, 5, 5, 5}};
    int size1 = 4;

    std::vector<std::vector<int>> max_submatrix1 = max_submatrix(matrix1, size1);
    std::cout << "Maximum sum " << size1 << " x " << size1 << " matrix is" << std::endl;
    print_grid(max_submatrix1);

    // test 2
    std::vector<std::vector<int>> matrix2 = {{1, 1, 1, 1, 1},
                                            {3, 8, 6, 7, 3},
                                            {4, 4, 4, 4, 4},
                                            {5, 5, 5, 5, 5}};
    int size2 = 3;

    std::vector<std::vector<int>> max_submatrix2 = max_submatrix(matrix2, size2);
    std::cout << "Maximum sum " << size2 << " x " << size2 << " matrix is" << std::endl;
    print_grid(max_submatrix2);

    // test 3
    std::vector<std::vector<int>> matrix3 = {{1, 1, 1, 1, 1},
                                            {2, 2, 2, 2, 2},
                                            {3, -8, 6, 7, 3},
                                            {4, 4, 4, 4, 4},
                                            {5, 5, 5, 5, 5}};
    int size3 = 3;

    std::vector<std::vector<int>> max_submatrix3 = max_submatrix(matrix3, size3);
    std::cout << "Maximum sum " << size3 << " x " << size3 << " matrix is" << std::endl;
    print_grid(max_submatrix3);

    return 0;
}    