// PROBLEM:
/*
    Given a 2D binary grid which represents a map of '1's (land) and '0's (water), return the number of islands.
    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
    The edges of the grid are surrounded by water.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector

void nullify(std::vector<std::vector<char>>& grid_, int x_, int y_, int rows_, int cols_)
{
    if (x_ < 0 || y_ < 0 || x_ >= rows_ || y_ >= cols_ || '0' == grid_[x_][y_])
    {
        return;
    }
    grid_[x_][y_] =  '0';
    nullify(grid_, x_ + 1, y_, rows_, cols_);
    nullify(grid_, x_ - 1, y_, rows_, cols_);
    nullify(grid_, x_, y_ + 1, rows_, cols_);
    nullify(grid_, x_, y_ - 1, rows_, cols_);
}

int num_of_islands(std::vector<std::vector<char>>& grid_)
{
    int rows = grid_.size();
    int cols = grid_[0].size();
    int ret = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if ('1' == grid_[i][j])
            {
                ++ret;
                nullify(grid_, i, j, rows, cols);
            }
        }
    }
    return ret;
}


// SIMPLE TESTS:

int main()
{
    // test 1
    std::vector<std::vector<char>> map1 = {{'1','1','1','1','0'},
                                           {'1','1','0','1','0'},
                                           {'1','1','0','0','0'},
                                           {'0','0','0','0','0'}};
    std::cout << num_of_islands(map1) << std::endl;

    // test 2
    std::vector<std::vector<char>> map2 = {{'1','1','0','0','0'},
                                           {'1','1','0','0','0'},
                                           {'0','0','1','0','0'},
                                           {'0','0','0','1','1'}};
    std::cout << num_of_islands(map2) << std::endl;

    return 0;
}