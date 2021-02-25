/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        vector<int> vec;
        queue<TreeNode *> level;
        if (root != nullptr)
        {
            level.push(root);
        }
        int size;
        while (!level.empty())
        {
            size = level.size();
            vec.clear();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = level.front();
                level.pop();
                vec.push_back(node->val);
                if (node->left)
                    level.push(node->left);
                if (node->right)
                    level.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};
// @lc code=end
