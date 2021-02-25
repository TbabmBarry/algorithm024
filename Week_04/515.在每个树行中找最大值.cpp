/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        queue<TreeNode *> level;
        int maxLevel, size;
        if (root != nullptr)
            level.push(root);
        while (!level.empty())
        {
            maxLevel = INT_MIN;
            size = level.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = level.front();
                level.pop();
                maxLevel = max(node->val, maxLevel);
                if (node->left)
                    level.push(node->left);
                if (node->right)
                    level.push(node->right);
            }
            res.push_back(maxLevel);
        }
        return res;
    }
};
// @lc code=end
