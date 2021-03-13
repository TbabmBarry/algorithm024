/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (!n || n == 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(2 * k + 1, 0));
        for (int j = 1; j < 2 * k; j += 2)
        {
            dp[0][j] = -prices[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 2 * k - 1; j += 2)
            {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }
        return dp[n - 1][2 * k];
    }
};
// @lc code=end
