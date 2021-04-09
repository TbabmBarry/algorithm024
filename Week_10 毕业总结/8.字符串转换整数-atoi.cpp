/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.length(), idx = 0, sign = 1, res = 0;
        for (const auto &c : s)
        {
            if (c != ' ')
                break;
            idx++;
        }
        if (idx == n)
            return res;
        if (s[idx] == '+')
            idx++;
        else if (s[idx] == '-')
        {
            sign = -1, idx++;
        }
        for (int i = idx; i < n; i++)
        {
            char ch = s[i];
            if (!isdigit(ch))
                break;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (ch - '0' > INT_MAX % 10)))
                return INT_MAX;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && (ch - '0' > -(INT_MIN % 10))))
                return INT_MIN;
            res = res * 10 + sign * (ch - '0');
        }
        return res;
    }
};
// @lc code=end
