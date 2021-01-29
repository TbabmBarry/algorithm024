#
# @lc app=leetcode.cn id=11 lang=python3
#
# [11] 盛最多水的容器
#

# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        curr = res = 0
        while left < right:
            curr = min(height[left], height[right]) * (right - left)
            res = max(res, curr)
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return res
# @lc code=end
