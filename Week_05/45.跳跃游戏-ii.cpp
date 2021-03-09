/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int curr_cover = 0, next_cover = 0, res = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            next_cover = max(next_cover, i + nums[i]);
            if (i == curr_cover)
            {
                curr_cover = next_cover;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
