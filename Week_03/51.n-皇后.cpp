/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> chessboard(n, string(n, '.'));
        back_track(res, n, 0, chessboard);
        return res;
    }

    void back_track(vector<vector<string>> &res, int n, int row, vector<string> &chessboard)
    {
        if (row == n)
        {
            res.push_back(chessboard);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isValid(row, col, chessboard, n))
            {
                chessboard[row][col] = 'Q';
                back_track(res, n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }

    bool isValid(int row, int col, vector<string> &chessboard, int n)
    {
        int count = 0;
        for (int i = 0; i < row; i++)
        {
            if (chessboard[i][col] == 'Q')
            {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j >= 0; i--, j++)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
