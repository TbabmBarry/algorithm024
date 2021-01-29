#
# @lc app=leetcode.cn id=24 lang=python3
#
# [24] 两两交换链表中的节点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not (head and head.next):
            return head

        a = ListNode(-1)
        curr, head, stack = head, a, []
        while curr and curr.next:
            curr_next = curr.next
            curr.next = None
            stack.append(curr)
            curr_next_next = curr_next.next
            curr_next.next = None
            stack.append(curr_next)

            curr = curr_next_next

            a.next = stack.pop()
            a.next.next = stack.pop()

            a = a.next.next
        if curr:
            a.next = curr
        else:
            a.next = None
        return head.next
# @lc code=end
