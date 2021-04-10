/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size(), 1);
        int l = 1, r = 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--)
        {
            res[i] *= l;
            res[j] *= r;
            l *= nums[i];
            r *= nums[j];
        }
        return res;
    }
};
// @lc code=end
