/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution
{
public:
    void dfs(string &beginWord, string &currWord, vector<string> path, unordered_map<string, vector<string>> &neighbor, vector<vector<string>> &res)
    {
        if (currWord == beginWord)
        {
            path.push_back(currWord);
            reverse(path.begin(), path.end());
            res.push_back(path);
            return;
        }
        path.push_back(currWord);
        for (string word : neighbor[currWord])
        {
            dfs(beginWord, word, path, neighbor, res);
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> res;
        vector<string> path;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord))
            return res;
        unordered_map<string, int> visitMap;
        unordered_map<string, vector<string>> neighbor;
        visitMap[beginWord] = 1;
        queue<string> level;
        level.push(beginWord);
        while (!level.empty())
        {
            string word = level.front();
            level.pop();
            for (int i = 0; i < word.size(); i++)
            {
                string currWord = word;
                for (int j = 0; j < 26; j++)
                {
                    currWord[i] = j + 'a';
                    if (wordSet.count(currWord))
                    {
                        if (!visitMap.count(currWord))
                        {
                            visitMap[currWord] = visitMap[word] + 1;
                            level.push(currWord);
                            neighbor[currWord].push_back(word);
                        }
                        else if (visitMap[currWord] == visitMap[word] + 1)
                        {
                            neighbor[currWord].push_back(word);
                        }
                    }
                }
            }
        }
        dfs(beginWord, endWord, path, neighbor, res);
        return res;
    }
};
// @lc code=end
