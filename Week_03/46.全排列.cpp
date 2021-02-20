/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        back_track(res, nums, 0);
        return res;
    }

    void back_track(vector<vector<int>> &res, vector<int> &nums, int start)
    {
        if (start == nums.size() - 1)
        {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            back_track(res, nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }
};
// @lc code=end
