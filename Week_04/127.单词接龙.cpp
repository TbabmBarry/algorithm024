/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
            return 0;
        queue<string> level;
        level.push(beginWord);
        unordered_map<string, int> visitMap;
        visitMap[beginWord] = 1;
        int path;
        while (!level.empty())
        {
            string word = level.front();
            level.pop();
            path = visitMap[word];
            for (int i = 0; i < word.size(); i++)
            {
                string currWord = word;
                for (int j = 0; j < 26; j++)
                {
                    currWord[i] = j + 'a';
                    if (currWord == endWord)
                        return path + 1;
                    if (wordSet.find(currWord) != wordSet.end() && visitMap.find(currWord) == visitMap.end())
                    {
                        visitMap[currWord] = path + 1;
                        level.push(currWord);
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end
