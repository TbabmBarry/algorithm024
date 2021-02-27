/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = s.size() - 1, res = 0;
        for (int i = g.size() - 1; i >= 0; i--)
        {
            if (j >= 0 && s[j] >= g[i])
            {
                res++;
                j--;
            }
        }
        return res;
    }
};
// @lc code=end
