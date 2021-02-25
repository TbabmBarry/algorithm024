/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int a = 0, b = 0, c = 0;
        for (int bill : bills)
        {
            if (bill == 5)
                a++;
            if (bill == 10)
            {
                if (a < 1)
                {
                    return false;
                }
                a--;
                b++;
            }
            if (bill == 20)
            {
                if (a > 0 && b > 0)
                {
                    a--;
                    b--;
                    c++;
                }
                else if (a > 2)
                {
                    a -= 3;
                    c++;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
