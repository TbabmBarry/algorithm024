/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution
{
public:
    int findLength(vector<int> &A, vector<int> &B)
    {
        int m = A.size(), n = B.size(), res = 0;
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            for (int j = n; j > 0; j--)
            {
                if (A[i - 1] == B[j - 1])
                {
                    dp[j] = dp[j - 1] + 1;
                }
                else
                    dp[j] = 0;
                res = max(dp[j], res);
            }
        }
        return res;
    }
};
// @lc code=end
