/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        long res = 0, curRes = 0, num = 0, n = s.size();
        char op = '+';
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1)
            {
                switch (op)
                {
                case '+':
                    curRes += num;
                    break;
                case '-':
                    curRes -= num;
                    break;
                case '*':
                    curRes *= num;
                    break;
                case '/':
                    curRes /= num;
                    break;
                }
                if (c == '+' || c == '-' || i == n - 1)
                {
                    res += curRes;
                    curRes = 0;
                }
                op = c;
                num = 0;
            }
        }
        return res;
    }
};
// @lc code=end
