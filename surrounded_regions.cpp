// PROBLEM:
/*  
    Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
    A region is captured by flipping all 'O's into 'X's in that surrounded region.
    Notice that an 'O' should not be flipped if:
    - It is on the border.
    - It is adjacent to an 'O' that should not be flipped.
*/


// SOLUTION:

#include <vector> // vector
#include <iostream> // cout
#include <deque> // deque
#include <utility> // pair

void capture(std::vector<std::vector<char>>& board_, int x_, int y_, int rows_, int cols_)
{
    if (x_ < 0 ||
        y_ < 0 ||
        x_ >= rows_ ||
        y_ >= cols_ ||
        'O' != board_[x_][y_])
    {
        return;
    }   
    board_[x_][y_] = '1';
    capture(board_, x_ + 1, y_, rows_, cols_);
    capture(board_, x_ - 1, y_, rows_, cols_);
    capture(board_, x_, y_ + 1, rows_, cols_);
    capture(board_, x_, y_ - 1, rows_, cols_);
}

void solve(std::vector<std::vector<char>>& board_)
{
    int rows = board_.size();
    if (rows)
    {
        int cols = board_[0].size();

        for (int i = 0; i < rows; ++i)
        {
            if ('O' == board_[i][0])
            {
                capture(board_, i, 0, rows, cols);
            }
            if ('O' == board_[i][cols - 1])
            {
                capture(board_, i, cols-1, rows, cols);
            }
        }
        
        for (int j = 0; j < cols; ++j)
        {
            if ('O' == board_[0][j])
            {
                capture(board_, 0, j, rows, cols);
            }
            if ('O' == board_[rows-1][j])
            {
                capture(board_, rows-1, j, rows, cols);
            }
        }
        
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if('O' == board_[i][j])
                {
                    board_[i][j] = 'X';
                }
                else if ('1' == board_[i][j])
                {
                    board_[i][j] = 'O';
                }
            }
        }
    }
}


// SIMPLE TESTS:

void print_board(std::vector<std::vector<char>>& board_)
{
    for (size_t i = 0; i < board_.size(); ++i)
    {
        for (size_t j = 0; j < board_[0].size(); ++j)
        {
            std::cout << board_[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    // test 1
    std::vector<std::vector<char>> board1 = {{'X','X','X','X'},
                                             {'X','O','O','X'},
                                             {'X','X','O','X'},
                                             {'X','O','X','X'}};
    print_board(board1);
    solve(board1);
    print_board(board1);
    std::cout << std::endl;


    // test 2
    std::vector<std::vector<char>> board2 = {{'O','O','O','O','X','X'},
                                             {'O','O','O','O','O','O'},
                                             {'O','X','O','X','O','O'},
                                             {'O','X','O','O','X','O'},
                                             {'O','X','O','X','O','O'},
                                             {'O','X','O','O','O','O'}};
    print_board(board2);
    solve(board2);
    print_board(board2);
    std::cout << std::endl;

    // test 3
    std::vector<std::vector<char>> board3 = {{'O','X','O','O','O','O','O','O','O'},
                                             {'O','O','O','X','O','O','O','O','X'},
                                             {'O','X','O','X','O','O','O','O','X'},
                                             {'O','O','O','O','X','O','O','O','O'},
                                             {'X','O','O','O','O','O','O','O','X'},
                                             {'X','X','O','O','X','O','X','O','X'},
                                             {'O','O','O','X','O','O','O','O','O'},
                                             {'O','O','O','X','O','O','O','O','O'},
                                             {'O','O','O','O','O','X','X','O','O'}};                
    print_board(board3);
    solve(board3);
    print_board(board3);
    std::cout << std::endl;

    // test 4
    std::vector<std::vector<char>> board4 = {{'O','X','O','O','X','X'},
                                             {'O','X','X','X','O','X'},
                                             {'X','O','O','X','O','O'},
                                             {'X','O','X','X','X','X'},
                                             {'O','O','X','O','X','X'},
                                             {'X','X','O','O','O','O'}};
    print_board(board4);
    solve(board4);
    print_board(board4);
    std::cout << std::endl;  

    // test 5
    std::vector<std::vector<char>> board5 = {};
    print_board(board5);
    solve(board5);
    print_board(board5);
    std::cout << std::endl; 


    std::cout << "All tets passed." << std::endl;

    return 0;
}