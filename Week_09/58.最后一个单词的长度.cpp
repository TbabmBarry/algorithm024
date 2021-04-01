/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (!s.size())
            return 0;
        stringstream ss(s);
        string word;
        while (ss >> word)
        {
        }
        return word.size();
    }
};
// @lc code=end
