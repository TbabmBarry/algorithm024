/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            Node *node = st.top();
            res.push_back(node->val);
            st.pop();
            size_t n = node->children.size();
            for (int i = n - 1; i >= 0; i--)
            {
                if (node->children[i] != nullptr)
                {
                    st.push(node->children[i]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
