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
        backtrack(res, nums, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &nums, int idx)
    {
        if (idx == nums.size() - 1)
        {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            backtrack(res, nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
};
// @lc code=end
