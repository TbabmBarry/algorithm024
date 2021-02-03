#
# @lc app=leetcode.cn id=590 lang=python3
#
# [590] N叉树的后序遍历
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
    def postorder(self, root: 'Node') -> List[int]:
        if root is None:
            return []

        stack, output = [root], []
        while stack:
            root = stack.pop()
            if root is not None:
                output.append(root.val)
            for child in root.children:
                stack.append(child)
        return output[::-1]
# @lc code=end
