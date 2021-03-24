/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 */

// @lc code=start
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size(), second = INT_MIN;
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < second)
                return true;
            while (!st.empty() && nums[st.top()] < nums[i])
            {
                second = nums[st.top()];
                st.pop();
            }
            st.push(i);
        }
        return false;
    }
};
// @lc code=end
