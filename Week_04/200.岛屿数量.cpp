/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        const int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    helper(grid, i, j);
                }
            }
        }
        return res;
    }

    void helper(vector<vector<char>> &grid, int ii, int jj)
    {
        const int row = grid.size(), col = grid[0].size();
        if (ii < 0 || ii >= row || jj < 0 || jj >= col || grid[ii][jj] == '0')
            return;
        grid[ii][jj] = '0';
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int new_i = ii + dx[i];
            int new_j = jj + dy[i];
            helper(grid, new_i, new_j);
        }
    }
};
// @lc code=end
