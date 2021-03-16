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
        vector<string> cb(n, string(n, '.'));
        back_track(res, n, 0, cb);
        return res;
    }

    void back_track(vector<vector<string>> &res, int n, int row, vector<string> &cb)
    {
        if (row == n)
        {
            res.push_back(cb);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isValid(n, row, col, cb))
            {
                cb[row][col] = 'Q';
                back_track(res, n, row + 1, cb);
                cb[row][col] = '.';
            }
        }
    }

    bool isValid(int n, int row, int col, vector<string> &cb)
    {
        for (int i = 0; i < row; i++)
        {
            if (cb[i][col] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (cb[i][j] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (cb[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
