/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int dp[2];
        dp[0] = -prices[0];
        dp[1] = 0;
        int tmp;
        for (int i = 1; i < n; i++)
        {
            tmp = dp[0];
            dp[0] = max(dp[0], -prices[i]);
            dp[1] = max(dp[1], tmp + prices[i]);
        }
        return dp[1];
    }
};
// @lc code=end
