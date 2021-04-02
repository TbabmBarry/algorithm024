/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        int sub = 0;
        string tmp;
        unordered_map<string, int> hashmap;
        for (const auto &str : strs)
        {
            tmp = str;
            sort(tmp.begin(), tmp.end());
            if (hashmap.count(tmp))
            {
                res[hashmap[tmp]].push_back(str);
            }
            else
            {
                vector<string> vec(1, str);
                res.push_back(vec);
                hashmap[tmp] = sub++;
            }
        }
        return res;
    }
};
// @lc code=end
