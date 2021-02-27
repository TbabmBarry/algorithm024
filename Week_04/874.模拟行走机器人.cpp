/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int ii = 0, jj = 0, dir = 0, res = 0;
        set<pair<int, int>> obsSet;
        for (const auto &obs : obstacles)
        {
            obsSet.insert({obs[0], obs[1]});
        }
        int dx[4]{0, 1, 0, -1};
        int dy[4]{1, 0, -1, 0};
        for (const auto &command : commands)
        {
            if (command == -1)
            {
                dir = (dir + 1) % 4;
            }
            else if (command == -2)
            {
                dir = (dir + 3) % 4;
            }
            else
            {
                for (int i = 0; i < command; i++)
                {
                    if (!obsSet.count({ii + dx[dir], jj + dy[dir]}))
                    {
                        ii += dx[dir];
                        jj += dy[dir];
                    }
                    else
                    {
                        break;
                    }
                    res = max(res, ii * ii + jj * jj);
                }
            }
        }
        return res;
    }
};
// @lc code=end
