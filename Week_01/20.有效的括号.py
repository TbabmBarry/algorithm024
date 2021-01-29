#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 == 1:
            return False

        stack = []
        pairs = {
            "(": ")",
            "[": "]",
            "{": "}"
        }

        for i in s:
            if i in pairs:
                stack.append(i)
            else:
                if not stack or pairs[stack[-1]] != i:
                    return False
                stack.pop()
        return not stack


# @lc code=end
