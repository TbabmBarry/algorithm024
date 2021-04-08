/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
    int left = 0, maxLen = 0;

public:
    string longestPalindrome(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            helper(s, i, i);
            helper(s, i, i + 1);
        }
        return s.substr(left, maxLen);
    }

    void helper(const string &s, int l, int r)
    {
        while (l >= 0 && r < s.length())
        {
            if (s[l] != s[r])
                break;
            l--, r++;
        }
        if (r - l - 1 > maxLen)
        {
            left = l + 1, maxLen = r - l - 1;
        }
    }
};
// @lc code=end
