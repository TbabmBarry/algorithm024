/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int row[9][9]{0}, col[9][9]{0}, grid[9][9]{0};
        int n;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    n = board[i][j] - '1';

                    if (row[i][n] != 0 || col[j][n] != 0 || grid[(i / 3) * 3 + (j / 3)][n] != 0)
                    {
                        return false;
                    }

                    row[i][n] = 1;
                    col[j][n] = 1;
                    grid[(i / 3) * 3 + (j / 3)][n] = 1;
                }
            }
        }
        return true;
    }
};
// @lc code=end
