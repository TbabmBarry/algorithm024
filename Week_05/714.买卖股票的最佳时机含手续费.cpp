/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        int dp[2];
        int temp = 0;
        dp[0] = -prices[0];
        dp[1] = 0;
        for (int i = 1; i < n; i++)
        {
            temp = dp[0];
            dp[0] = max(dp[0], dp[1] - prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i] - fee);
        }
        return dp[1];
    }
};
// @lc code=end
