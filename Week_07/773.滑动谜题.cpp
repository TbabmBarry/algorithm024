/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start
class Solution
{
public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        int m = board.size(), n = board[0].size();
        string target = "123450";
        string begin;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                begin += to_string(board[i][j]);
            }
        }

        vector<vector<int>> dir{{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        unordered_set<string> visited{begin};
        queue<string> q{{begin}};
        for (int depth = 0; !q.empty(); ++depth)
        {
            size_t size = q.size();
            for (int i = 0; i < size; ++i)
            {
                auto curr = q.front();
                q.pop();
                if (curr == target)
                {
                    return depth;
                }
                int zero_index = curr.find("0");
                for (const auto &d : dir[zero_index])
                {
                    auto temp = curr;
                    swap(temp[zero_index], temp[d]);
                    if (visited.find(temp) == visited.end())
                    {
                        visited.emplace(temp);
                        q.emplace(temp);
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
