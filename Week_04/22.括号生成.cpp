/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        back_track(res, "", n, n);
        return res;
    }
    void back_track(vector<string> &res, string curr, int lp, int rp)
    {
        if (lp == 0 && rp == 0)
        {
            res.push_back(curr);
            return;
        }
        if (lp > 0)
        {
            back_track(res, curr + "(", lp - 1, rp);
        }
        if (rp > lp)
        {
            back_track(res, curr + ")", lp, rp - 1);
        }
    }
};
// @lc code=end
