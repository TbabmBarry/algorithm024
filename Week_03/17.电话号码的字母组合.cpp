/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    unordered_map<char, string> map = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> res;
    string curr;
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return res;
        }
        back_track(0, digits);
        return res;
    }

    void back_track(int idx, string digits)
    {
        if (idx == digits.size())
        {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < map[digits[idx]].size(); i++)
        {
            curr.push_back(map[digits[idx]][i]);
            back_track(idx + 1, digits);
            curr.pop_back();
        }
    }
};
// @lc code=end
