/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (!nums.size())
            return 0;
        vector<int> dp(nums.size(), 0);
        int res = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (res < dp[i])
                res = dp[i];
        }
        return res;
    }
};
// @lc code=end
