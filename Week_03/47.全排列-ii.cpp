/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> track;
        vector<bool> ind(nums.size(), false);
        sort(nums.begin(), nums.end());
        back_track(res, nums, track, ind);
        return res;
    }

    void back_track(vector<vector<int>> &res, vector<int> &nums, vector<int> &track, vector<bool> &ind)
    {
        if (track.size() == nums.size())
        {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && !ind[i - 1])
            {
                continue;
            }
            if (ind[i] == false)
            {
                ind[i] = true;
                track.push_back(nums[i]);
                back_track(res, nums, track, ind);
                track.pop_back();
                ind[i] = false;
            }
        }
    }
};
// @lc code=end
