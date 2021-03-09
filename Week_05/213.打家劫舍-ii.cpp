/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        return max(helper(nums, 0), helper(nums, 1));
    }

    int helper(vector<int> &nums, int start)
    {
        vector<int> dp(nums.size(), 0);
        int end = nums.size() - 2 + start;
        if (end == start)
            return nums[start];
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }
};
// @lc code=end
