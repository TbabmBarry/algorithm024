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

    void back_track(vector<string> &res, string curr, int l, int r)
    {
        // terminator
        if (l == 0 && r == 0)
        {
            res.push_back(curr);
            return;
        }
        if (l < r)
        {
            back_track(res, curr + ")", l, r - 1);
        }
        if (l > 0)
        {
            back_track(res, curr + "(", l - 1, r);
        }
    }
};
// @lc code=end
