/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        vector<unsigned int> dp(n + 1, 1);
        for (const auto &c : t)
        {
            auto last = dp[0];
            dp[0] = 0;
            for (int j = 1; j <= n; j++)
            {
                auto record = dp[j];
                if (s[j - 1] == c)
                    dp[j] = last + dp[j - 1];
                else
                    dp[j] = dp[j - 1];
                last = record;
            }
        }
        return dp[n];
    }
};
// @lc code=end
