/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int a = 1;
        while (num > 0)
        {
            num -= a;
            a += 2;
        }
        return num == 0;
    }
};
// @lc code=end
