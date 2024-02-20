// PROBLEM:
/*
    A robot is at the top-left corner of a grid with r rows and c columns.
    The robot can move only to the right and downward, but some cells cannot be moved to.
    Design an algorithm for the robot to find the way from the top left to the bottom right.
*/


// SOLUTION:

#include <iostream> // cout
#include <vector> // vector

int move_one(std::vector<std::vector<int>>& grid_, int rows_, int cols_)
{
    if (rows_ < 0 || cols_ < 0 || (-1 == grid_[rows_][cols_]))
    {
        return 0;
    }
    if (!cols_&& !rows_)
    {
        grid_[rows_][cols_] = 1;
        return 1;
    }

    int ret = move_one(grid_, rows_ - 1, cols_);
    if (ret)
    {
        grid_[rows_][cols_] = ret;
        return ret;
    }
    ret = move_one(grid_, rows_, cols_ - 1);
    grid_[rows_][cols_] = ret;
    return ret;
}

void grid_robot(std::vector<std::vector<int>>& grid_)
{
    int rows_ = grid_.size();
    int cols_ = grid_[0].size();
    int left = move_one(grid_, rows_-1, cols_ - 2);
    if (left)
    {
        std::cout << "Success." << std::endl;
        return;
    }
    int up = move_one(grid_, rows_ - 2, cols_ - 1);
    if (up)
    {
        std::cout << "Success." << std::endl;
        return;
    }
    std::cout << "Failure." << std::endl;
}


 // SIMPLE TESTS:

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
    std::vector<std::vector<int>> grid_1 = {{0, 0, -1, 0, 0},
                                            {0, 0, 0, 0, 0},
                                            {0, -1, 0, -1, 0},
                                            {-1, -1, 0, -1, -1},
                                            {0, 0, 0, 0, 0}};
    std::cout << "Trying grid 1: " << std::endl;
    grid_robot(grid_1);
    print_grid(grid_1);

    // test 2
    std::vector<std::vector<int>> grid_2 = {{0, 0, -1, 0, 0},
                                            {0, 0, 0, 0, 0},
                                            {0, -1, -1, -1, 0},
                                            {-1, -1, 0, -1, -1},
                                            {0, 0, 0, 0, 0}};
    std::cout << "Trying grid 2: " << std::endl;
    grid_robot(grid_2);
    print_grid(grid_2);
    
    return 0;
 }