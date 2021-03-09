/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (!n)
            return 0;
        int dp[3];
        dp[0] = -prices[0];
        dp[1] = 0;
        dp[2] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[0] = max(dp[0], dp[1] - prices[i]);
            dp[1] = max(dp[2], dp[1]);
            dp[2] = dp[0] + prices[i];
        }
        return max(dp[1], dp[2]);
    }
};
// @lc code=end
