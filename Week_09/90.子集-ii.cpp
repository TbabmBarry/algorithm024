/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        trackback(nums, 0, res, path);
        return res;
    }

    void trackback(vector<int> &nums, int begin, vector<vector<int>> &res, vector<int> path)
    {
        res.push_back(path);
        for (int i = begin; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            trackback(nums, i + 1, res, path);
            path.pop_back();
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
    }
};
// @lc code=end
