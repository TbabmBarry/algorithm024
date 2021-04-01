/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int hashmap[26]{0};
        for (int i = 0; i < s.size(); i++)
        {
            hashmap[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (hashmap[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end
