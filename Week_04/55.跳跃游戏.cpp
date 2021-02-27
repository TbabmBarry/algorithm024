/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int cover = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > cover)
                return false;
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size())
                break;
        }
        return true;
    }
};
// @lc code=end
