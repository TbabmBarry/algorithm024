/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        if (!m || !n)
            return;
        for (int u = 0; u < m; u++)
        {
            dfs(board, u, 0);
            dfs(board, u, n - 1);
        }
        for (int v = 1; v < n - 1; v++)
        {
            dfs(board, 0, v);
            dfs(board, m - 1, v);
        }
        for (int u = 0; u < m; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (board[u][v] == 'V')
                {
                    board[u][v] = 'O';
                }
                else if (board[u][v] == 'O')
                {
                    board[u][v] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O')
        {
            return;
        }
        board[i][j] = 'V';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};
// @lc code=end
