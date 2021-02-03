#
# @lc app=leetcode.cn id=429 lang=python3
#
# [429] N 叉树的层序遍历
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        res = []
        arr = collections.deque([root])
        while arr:
            level = []
            for i in range(len(arr)):
                root = arr.popleft()
                level.append(root.val)
                for child in root.children:
                    arr.append(child)
            res.append(level)
        return res
# @lc code=end
