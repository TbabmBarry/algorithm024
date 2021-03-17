/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicates(string S)
    {
        string res;
        for (const auto &c : S)
        {
            if (res.empty() || res.back() != c)
            {
                res.push_back(c);
            }
            else
            {
                res.pop_back();
            }
        }
        return res;
    }
};
// @lc code=end
