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
        int curr = s.length() - 1, tmpLen;
        string res;
        while (curr >= 0)
        {
            tmpLen = 0;
            while (curr >= 0 && s[curr] == ' ')
                curr--;
            while (curr >= 0 && s[curr] != ' ')
            {
                curr--, tmpLen++;
            }
            if (tmpLen)
                res += s.substr(curr + 1, tmpLen) + " ";
        }
        return res.substr(0, res.length() - 1);
    }
};
// @lc code=end
