/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int count[256]{0};
        for (auto &c : t)
        {
            count[c]++;
        }
        int l = 0, r = 0, len = 0, minLen = s.size();
        string res;
        while (r < s.size())
        {
            if (--count[s[r]] >= 0)
            {
                len++;
            }
            while (len == t.size())
            {
                if (r - l + 1 <= minLen)
                {
                    minLen = r - l + 1;
                    res = s.substr(l, minLen);
                }
                if (++count[s[l++]] > 0)
                {
                    len--;
                }
            }
            r++;
        }
        return res;
    }
};
// @lc code=end
