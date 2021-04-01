/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, -1);
        if (!n)
            return res;
        stack<int> st;
        for (int i = 0; i < n * 2; i++)
        {
            while (!st.empty() && nums[i % n] > nums[st.top()])
            {
                res[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return res;
    }
};
// @lc code=end
