/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        queue<string> level;
        unordered_set<string> dnaBank(bank.begin(), bank.end());
        unordered_set<string> isVisited;
        level.emplace(start);
        isVisited.emplace(start);
        int res = 0;
        while (!level.empty())
        {
            size_t size = level.size();
            while (size--)
            {
                string dna = level.front();
                level.pop();
                if (dna == end)
                    return res;
                for (int i = 0; i < dna.size(); i++)
                {
                    string temp = dna;
                    for (auto &ch : {'A', 'C', 'G', 'T'})
                    {
                        if (dna[i] != ch)
                            temp[i] = ch;
                        if (!dnaBank.count(temp) || !isVisited.emplace(temp).second)
                            continue;
                        level.emplace(temp);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
// @lc code=end
