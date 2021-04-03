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
        string res = "";
        int map[128]{0};
        int l = 0, r = 0, need = t.size(), minstart = 0, minlen = INT_MAX;
        for (char c : t)
        {
            map[c]++;
        }
        while (r < s.size())
        {
            if (map[s[r]] > 0)
                need--;
            map[s[r]]--;
            r++;
            while (need == 0)
            {
                if (r - l < minlen)
                {
                    minstart = l, minlen = r - l;
                }
                map[s[l]]++;
                if (map[s[l]] > 0)
                    need++;
                l++;
            }
        }
        if (minlen != INT_MAX)
            res = s.substr(minstart, minlen);
        return res;
    }
};
// @lc code=end
