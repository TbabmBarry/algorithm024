/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        int l = 0, r = 0;
        if (!n || n == 1)
            return s;
        for (int i = 0; i < n; i++)
        {
            if (s[i + 1] == ' ' || s[i + 1] == '\0')
            {
                r = i;
                while (l < r)
                {
                    swap(s[l], s[r]);
                    l++, r--;
                }
                l = i + 2;
                r = l;
            }
        }
        return s;
    }
};
// @lc code=end
