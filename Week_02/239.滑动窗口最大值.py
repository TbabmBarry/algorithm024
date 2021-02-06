#
# @lc app=leetcode.cn id=239 lang=python3
#
# [239] 滑动窗口最大值
#

# @lc code=start
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res, arr = [], collections.deque()
        for i in range(len(nums)):
            if arr and arr[0] <= (i - k):
                arr.popleft()
            while arr and nums[arr[-1]] < nums[i]:
                arr.pop()
            arr.append(i)
            if i + 1 >= k:
                res.append(nums[arr[0]])
        return res
# @lc code=end
