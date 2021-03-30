/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (!n)
            return 0;
        if (n == 1)
            return nums[0];
        int dp[n];
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        int res = dp[1], tmp;
        for (int i = 2; i < n; i++)
        {
            tmp = max(dp[1], dp[0] + nums[i]);
            res = max(tmp, res);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return res;
    }
};
// @lc code=end
