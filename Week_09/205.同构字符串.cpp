/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        for (int i = 0, j = 0; i < s.size(); i++, j++)
        {
            if (map1.find(s[i]) == map1.end())
            {
                map1[s[i]] = t[j];
            }
            if (map2.find(t[j]) == map2.end())
            {
                map2[t[j]] = s[i];
            }
            if (map1[s[i]] != t[j] || map2[t[j]] != s[i])
                return false;
        }
        return true;
    }
};
// @lc code=end
