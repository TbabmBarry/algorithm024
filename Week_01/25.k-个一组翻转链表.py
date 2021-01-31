#
# @lc app=leetcode.cn id=25 lang=python3
#
# [25] K 个一组翻转链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head or k < 2:
            return head
        dummy = ListNode(-1)
        dummy.next = head
        left = dummy
        right = head
        count = 0
        while right:
            count += 1
            if count % k == 0:
                left = self.reverse(left, right.next)
                right = left.next
            else:
                right = right.next
        return dummy.next

    def reverse(self, start: ListNode, end: ListNode):
        prev = start
        curr = start.next
        temp = curr
        while curr != end:
            curr.next, prev, curr = prev, curr, curr.next
        start.next = prev
        temp.next = curr
        return temp

# @lc code=end
