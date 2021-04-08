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
        int hashmap[128]{};
        int l = 0, r = 0, need = 0;
        for (const auto &c : p)
        {
            hashmap[c]++;
        }
        while (r < s.length())
        {
            if (hashmap[s[r]] > 0)
                need++;
            hashmap[s[r]]--;
            r++;
            while (need == p.length())
            {
                if (r - l == p.length())
                    res.push_back(l);
                if (hashmap[s[l]] == 0)
                    need--;
                hashmap[s[l]]++;
                l++;
            }
        }
        return res;
    }
};
// @lc code=end
