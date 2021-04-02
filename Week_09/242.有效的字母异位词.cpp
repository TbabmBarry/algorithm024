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
        int hashmap[26]{0};
        for (const auto &c : s)
        {
            hashmap[c - 'a']++;
        }
        for (const auto &c : t)
        {
            hashmap[c - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (hashmap[i] != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
