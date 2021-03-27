/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        while (prev->next && prev->next->next)
        {
            ListNode *node1 = prev->next;
            ListNode *node2 = prev->next->next->next;
            prev->next = prev->next->next;
            prev->next->next = node1;
            prev->next->next->next = node2;
            prev = prev->next->next;
        }
        return dummy->next;
    }
};
// @lc code=end
