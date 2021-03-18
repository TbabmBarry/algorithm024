/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
class TrieNode
{
public:
    string word = "";
    vector<TrieNode *> nodes;
    TrieNode() : nodes(26, 0){};
};

class Solution
{
    int rows, cols;
    vector<string> res;

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        rows = board.size();
        cols = rows ? board[0].size() : 0;
        if (rows == 0 || cols == 0)
            return res;

        TrieNode *root = new TrieNode();
        for (const auto &word : words)
        {
            TrieNode *curr = root;
            for (int i = 0; i < word.size(); i++)
            {
                int idx = word[i] - 'a';
                if (curr->nodes[idx] == 0)
                {
                    curr->nodes[idx] = new TrieNode();
                }
                curr = curr->nodes[idx];
            }
            curr->word = word;
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                dfs(board, root, i, j);
            }
        }
        return res;
    }

    void dfs(vector<vector<char>> &board, TrieNode *root, int x, int y)
    {
        char ch = board[x][y];
        if (ch == '.' || root->nodes[ch - 'a'] == 0)
        {
            return;
        }
        root = root->nodes[ch - 'a'];
        if (root->word != "")
        {
            res.push_back(root->word);
            root->word = "";
        }

        board[x][y] = '.';
        if (x > 0)
            dfs(board, root, x - 1, y);
        if (y > 0)
            dfs(board, root, x, y - 1);
        if (x + 1 < rows)
            dfs(board, root, x + 1, y);
        if (y + 1 < cols)
            dfs(board, root, x, y + 1);
        board[x][y] = ch;
    }
};
// @lc code=end
