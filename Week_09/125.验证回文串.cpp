/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            while (i < n && !isalnum(s[i]))
                i++;
            while (j >= 0 && !isalnum(s[j]))
                j--;
            if (i < j && tolower(s[i++]) != tolower(s[j--]))
                return false;
        }
        return true;
    }
};
// @lc code=end
