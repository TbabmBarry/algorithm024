/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

// @lc code=start
class Solution
{
public:
    int clumsy(int N)
    {
        int n = N, res = 0, sign = 1, tmp;
        while (n > 0)
        {
            tmp = sign * n--;
            if (n > 0)
                tmp *= n--;
            if (n > 0)
                tmp /= n--;
            if (n > 0)
                tmp += n--;
            else
            {
                res += tmp;
                break;
            }
            res += tmp;
            sign = -1;
        }
        return res;
    }
};
// @lc code=end
