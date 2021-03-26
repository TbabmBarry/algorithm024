/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int hash[26]{0};
        for (const auto &c : s)
        {
            hash[c - 'a']++;
        }
        for (const auto &c : t)
        {
            hash[c - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (hash[i] != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
