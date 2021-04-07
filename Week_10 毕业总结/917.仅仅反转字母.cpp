/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        int n = S.length();
        int l = 0, r = n - 1;
        while (l < r)
        {
            if (!isalpha(S[l]))
                l++;
            if (!isalpha(S[r]))
                r--;
            if (isalpha(S[r]) && isalpha(S[l]))
            {
                swap(S[l], S[r]);
                l++, r--;
            }
        }
        return S;
    }
};
// @lc code=end
