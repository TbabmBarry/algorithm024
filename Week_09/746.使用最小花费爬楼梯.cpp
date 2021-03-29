/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int a = cost[0], b = cost[1], tmp;
        for (int i = 2; i < cost.size(); i++)
        {
            tmp = min(a, b) + cost[i];
            a = b;
            b = tmp;
        }
        return min(a, b);
    }
};
// @lc code=end
