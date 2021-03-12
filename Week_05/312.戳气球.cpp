/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len < n; len++)
        {
            for (int start = 0; start < n - len; start++)
            {
                int end = len + start;
                for (int k = start + 1; k < end; k++)
                {
                    dp[start][end] = max(dp[start][end], dp[start][k] + dp[k][end] + nums[start] * nums[k] * nums[end]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end
