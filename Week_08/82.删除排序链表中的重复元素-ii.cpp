/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        while (prev && prev->next)
        {
            ListNode *curr = prev->next;
            if (!curr->next || curr->next->val != curr->val)
                prev = curr;
            else
            {
                while (curr->next && curr->next->val == curr->val)
                    curr = curr->next;
                prev->next = curr->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end
