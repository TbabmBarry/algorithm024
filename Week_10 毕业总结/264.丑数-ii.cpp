/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int dp[n];
        dp[0] = 1;
        int tmp = 0, i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; i++)
        {
            tmp = min(2 * dp[i2], min(3 * dp[i3], 5 * dp[i5]));
            dp[i] = tmp;
            if (tmp == 2 * dp[i2])
                i2++;
            if (tmp == 3 * dp[i3])
                i3++;
            if (tmp == 5 * dp[i5])
                i5++;
        }
        return dp[n - 1];
    }
};
// @lc code=end
