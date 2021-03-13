/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

// @lc code=start
struct Node
{
    int val;
    Node *next;
    Node(int val) : val(val), next(nullptr) {}
};
const int len = 100;
class MyHashSet
{
public:
    vector<Node *> arr;
    /** Initialize your data structure here. */
    MyHashSet()
    {
        arr = vector<Node *>(len, new Node(-1));
    }

    void add(int key)
    {
        int position = key % len;
        Node *temp = arr[position];
        if (temp->val != -1)
        {
            while (temp)
            {
                if (temp->val == key)
                    return;
                if (!(temp->next))
                {
                    Node *node = new Node(key);
                    temp->next = node;
                    return;
                }
                temp = temp->next;
            }
        }
        else
        {
            temp->val = key;
            return;
        }
    }

    void remove(int key)
    {
        int position = key % len;
        Node *temp = arr[position];
        if (temp->val != -1)
        {
            while (temp)
            {
                if (temp->val == key)
                {
                    temp->val = -1;
                    return;
                }
                temp = temp->next;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int position = key % len;
        Node *temp = arr[position];
        while (temp)
        {
            if (temp->val == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
