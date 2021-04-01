/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        int i = s.size() - 1;
        string res;
        while (i >= 0)
        {
            int c = 0;
            while (i >= 0 && s[i] == ' ')
                --i;
            while (i >= 0 && s[i] != ' ')
            {
                --i;
                ++c;
            }
            if (c)
                res += s.substr(i + 1, c) + " ";
        }
        return res.substr(0, res.size() - 1);
    }
};
// @lc code=end
