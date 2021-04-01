/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        if (jewels.empty() || stones.empty())
            return 0;
        int res = 0;
        unordered_set<char> match;
        for (const auto &ch : jewels)
            match.insert(ch);
        for (const auto &ch : stones)
            res += match.count(ch);
        return res;
    }
};
// @lc code=end
