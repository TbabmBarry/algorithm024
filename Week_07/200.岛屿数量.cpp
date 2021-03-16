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
        for (int u = 0; u < grid.size(); u++)
        {
            for (int v = 0; v < grid[0].size(); v++)
            {
                if (grid[u][v] == '1')
                    res++;
                dfs(grid, u, v);
            }
        }
        return res;
    }

    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        {
            return;
        }
        int dx[4]{1, 0, -1, 0};
        int dy[4]{0, 1, 0, -1};
        grid[i][j] = '0';
        for (int k = 0; k < 4; k++)
        {
            dfs(grid, i + dx[k], j + dy[k]);
        }
    }
};
// @lc code=end
