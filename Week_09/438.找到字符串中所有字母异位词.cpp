/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        int map[128]{0};
        int l = 0, r = 0, need = 0, m = s.size(), n = p.size();
        for (char c : p)
        {
            map[c]++;
        }
        while (r < m)
        {
            if (map[s[r]] > 0)
                need++;
            map[s[r]]--;
            r++;
            while (need == n)
            {
                if (r - l == n)
                    res.push_back(l);
                if (!map[s[l]])
                    need--;
                map[s[l]]++;
                l++;
            }
        }
        return res;
    }
};
// @lc code=end
