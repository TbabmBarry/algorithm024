/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution
{
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        const int row = board.size(), col = board[0].size();

        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        queue<pair<int, int>> level;
        vector<vector<int>> seen(row, vector<int>(col));
        level.emplace(click[1], click[0]);
        seen[click[0]][click[1]]++;
        while (!level.empty())
        {
            const auto [x, y] = level.front();
            level.pop();

            int cnt = 0;
            for (int r = max(0, y - 1); r < min(row, y + 2); r++)
            {
                for (int c = max(0, x - 1); c < min(col, x + 2); c++)
                {
                    cnt += board[r][c] == 'M';
                }
            }
            if (cnt)
            {
                board[y][x] = cnt + '0';
                continue;
            }
            board[y][x] = 'B';
            for (int r = max(0, y - 1); r < min(row, y + 2); r++)
            {
                for (int c = max(0, x - 1); c < min(col, x + 2); c++)
                {
                    if (board[r][c] != 'E' || seen[r][c]++)
                        continue;
                    level.emplace(c, r);
                }
            }
        }
        return board;
    }
};
// @lc code=end
