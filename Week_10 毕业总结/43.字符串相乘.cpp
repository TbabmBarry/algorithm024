/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int m = num1.length(), n = num2.length();
        string s(m + n, '0');
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int curr = (num1[i] - '0') * (num2[j] - '0') + (s[i + j + 1] - '0');
                s[i + j + 1] = curr % 10 + '0';
                s[i + j] += curr / 10;
            }
        }
        for (int i = 0; i < m + n; i++)
        {
            if (s[i] != '0')
                return s.substr(i);
        }
        return "0";
    }
};
// @lc code=end
