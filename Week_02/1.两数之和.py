#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        res = {}
        for index, num in enumerate(nums):
            if res.get(target - num) is not None:
                return [res.get(target - num), index]
            res[num] = index
# @lc code=end
