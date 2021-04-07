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
        unordered_map<char, char> hashmap1;
        unordered_map<char, char> hashmap2;
        for (int i = 0, j = 0; i < s.length(); i++, j++)
        {
            if (hashmap1.find(s[i]) == hashmap1.end())
                hashmap1[s[i]] = t[j];
            if (hashmap2.find(t[j]) == hashmap2.end())
                hashmap2[t[j]] = s[i];
            if (hashmap1[s[i]] != t[j] || hashmap2[t[j]] != s[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
