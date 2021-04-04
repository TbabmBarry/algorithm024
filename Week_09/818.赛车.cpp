/*
 * @lc app=leetcode.cn id=818 lang=cpp
 *
 * [818] 赛车
 */

// @lc code=start
class Solution
{
    int dp[10001];

public:
    int racecar(int target)
    {
        if (dp[target] > 0)
            return dp[target];
        int n = floor(log2(target)) + 1, res;
        if (1 << n == target + 1)
            dp[target] = n;
        else
        {
            dp[target] = racecar((1 << n) - 1 - target) + n + 1;
            for (int m = 0; m < n; m++)
            {
                dp[target] = min(dp[target], racecar(target - (1 << (n - 1)) + (1 << m)) + n + m + 1);
            }
        }
        return dp[target];
    }
};
// @lc code=end
