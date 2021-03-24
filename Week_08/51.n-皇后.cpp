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
        backtrack(res, cb, n, 0);
        return res;
    }

    void backtrack(vector<vector<string>> &res, vector<string> &cb, int n, int row)
    {
        if (row == n)
        {
            res.push_back(cb);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (isValid(cb, n, row, j))
            {
                cb[row][j] = 'Q';
                backtrack(res, cb, n, row + 1);
                cb[row][j] = '.';
            }
        }
    }

    bool isValid(vector<string> &cb, int n, int row, int col)
    {
        for (int i = 0; i < n; i++)
        {
            if (cb[i][col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (cb[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && col < n; i--, j++)
        {
            if (cb[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
// @lc code=end
