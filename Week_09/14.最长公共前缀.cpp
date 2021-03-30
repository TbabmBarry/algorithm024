/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        if (strs.empty())
            return "";
        sort(strs.begin(), strs.end());
        for (int i = 0; i < min(strs[0].size(), strs[n - 1].size()); i++)
        {
            if (strs[0][i] != strs[n - 1][i])
                return strs[0].substr(0, i);
        }
        return strs[0];
    }
};
// @lc code=end
