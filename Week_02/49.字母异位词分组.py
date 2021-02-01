#
# @lc app=leetcode.cn id=49 lang=python3
#
# [49] 字母异位词分组
#

# @lc code=start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        maps = dict()
        for item in strs:
            key = tuple(sorted(item))
            maps[key] = maps.get(key, []) + [item]
        return list(maps.values())
# @lc code=end
