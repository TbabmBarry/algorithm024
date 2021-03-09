/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size(), res = nums[0];
        int curr_max = nums[0], curr_min = nums[0];
        int a = 0, b = 0;
        for (int i = 1; i < n; i++)
        {
            a = curr_max * nums[i];
            b = curr_min * nums[i];
            curr_max = max(max(a, b), nums[i]);
            curr_min = min(min(a, b), nums[i]);
            res = max(curr_max, res);
        }
        return res;
    }
};
// @lc code=end
