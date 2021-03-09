/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        for (int u = triangle.size() - 2; u >= 0; u--)
        {
            for (int v = 0; v < triangle[u].size(); v++)
            {
                triangle[u][v] += min(triangle[u + 1][v], triangle[u + 1][v + 1]);
            }
        }
        return triangle[0][0];
    }
};
// @lc code=end
