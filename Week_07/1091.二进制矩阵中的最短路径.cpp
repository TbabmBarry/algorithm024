/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;

        const vector<vector<int>> dir{{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        grid[0][0] = 2;

        int distance = 1;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == n - 1)
                    return distance;

                for (const auto &d : dir)
                {
                    int dx = x + d[0], dy = y + d[1];
                    if (dx < 0 || dx >= n || dy < 0 || dy >= n || grid[dx][dy] != 0)
                    {
                        continue;
                    }
                    grid[dx][dy] = 2;
                    q.emplace(dx, dy);
                }
            }
            distance++;
        }
        return -1;
    }
};
// @lc code=end
