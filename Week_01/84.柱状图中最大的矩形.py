#
# @lc app=leetcode.cn id=84 lang=python3
#
# [84] 柱状图中最大的矩形
#

# @lc code=start
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        heights = [-1] + heights + [-1]
        n = len(heights)
        res = 0
        for i in range(n):
            while stack and heights[stack[-1]] > heights[i]:
                res = max(res, heights[stack.pop()] * (i - stack[-1] - 1))
            stack.append(i)
        return res

# @lc code=end
