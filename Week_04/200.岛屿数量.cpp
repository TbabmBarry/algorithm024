/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution
{
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        const int row = grid.size(), col = grid[0].size();
        vector<bool> visited(row * col, false);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!visited[i * col + j] && grid[i][j] == '1')
                {
                    res++;
                    helper(grid, visited, i, j);
                }
            }
        }
        return res;
    }

    void helper(vector<vector<char>> &grid, vector<bool> &visited, int ii, int jj)
    {
        const int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < 4; i++)
        {
            int new_i = ii + dx[i];
            int new_j = jj + dy[i];
            if (new_i >= 0 && new_i < row && new_j >= 0 && new_j < col && !visited[new_i * col + new_j] && grid[new_i][new_j] == '1')
            {
                visited[new_i * col + new_j] = true;
                helper(grid, visited, new_i, new_j);
            }
        }
    }
};
// @lc code=end
