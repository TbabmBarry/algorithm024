/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 3)
        {
            return n;
        }
        int dp[2]{1, 2}, tmp;
        for (int i = 3; i <= n; i++)
        {
            tmp = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }
};
// @lc code=end
