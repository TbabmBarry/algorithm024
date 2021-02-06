#
# @lc app=leetcode.cn id=347 lang=python3
#
# [347] 前 K 个高频元素
#

# @lc code=start
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = dict()
        for num in nums:
            d[num] = d.get(num, 0) + 1
        d = sorted(d.items(), key=lambda d: d[1], reverse=True)
        return [d[i][0] for i in range(k)]
# @lc code=end
