/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.size();
        for (int i = 0; i < n; i += (2 * k))
        {
            int l = i;
            int r = min(i + k - 1, n - 1);
            while (l < r)
            {
                swap(s[l], s[r]);
                l++, r--;
            }
        }
        return s;
    }
};
// @lc code=end
