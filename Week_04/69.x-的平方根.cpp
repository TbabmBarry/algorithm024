/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        long long l = 0, r = x / 2 + 1, res, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            res = mid * mid;
            if (res == x)
            {
                return mid;
            }
            else if (res < x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r;
    }
};
// @lc code=end
