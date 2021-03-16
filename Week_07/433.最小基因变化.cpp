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
        unordered_set<string> bankSet(bank.begin(), bank.end());
        unordered_map<string, int> visited{{start, 0}};
        queue<string> q{{start}};
        while (!q.empty())
        {
            size_t size = q.size();
            while (size--)
            {
                const auto &curr = q.front();
                int steps = visited[curr];
                q.pop();
                if (curr == end)
                    return steps;
                for (int i = 0; i < 8; i++)
                {
                    string nxt(curr);
                    for (const auto &c : {'A', 'C', 'G', 'T'})
                    {
                        nxt[i] = c;
                        if (bankSet.count(nxt) && !visited.count(nxt))
                        {
                            visited.emplace(nxt, steps + 1);
                            q.emplace(nxt);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
