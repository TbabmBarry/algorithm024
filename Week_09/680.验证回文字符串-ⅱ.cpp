/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution
{
public:
    bool validPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return isValid(s, i + 1, j) || isValid(s, i, j - 1);
        }
        return true;
    }

    bool isValid(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};
// @lc code=end
