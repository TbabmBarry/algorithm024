/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(res, path, s, 0);
        return res;
    }

    void backtrack(vector<vector<string>> &res, vector<string> &path, const string &s, int startIndex)
    {
        if (startIndex == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isValid(s, startIndex, i))
            {
                string tmp = s.substr(startIndex, i - startIndex + 1);
                path.push_back(tmp);
            }
            else
            {
                continue;
            }
            backtrack(res, path, s, i + 1);
            path.pop_back();
        }
    }

    bool isValid(const string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};
// @lc code=end
