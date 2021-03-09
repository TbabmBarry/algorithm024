/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;
        for (int u = 1; u < m; u++)
        {
            for (int v = 1; v < n; v++)
            {
                dp[u][v] = dp[u - 1][v] + dp[u][v - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
