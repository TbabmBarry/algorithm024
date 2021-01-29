#
# @lc app=leetcode.cn id=283 lang=python3
#
# [283] 移动零
#

# @lc code=start
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = -1
        for j in range(len(nums)):
            if nums[j] != 0:
                i += 1
                nums[i], nums[j] = nums[j], nums[i]

# @lc code=end
