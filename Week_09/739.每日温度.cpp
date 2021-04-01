/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> res(T.size(), 0);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < T.size(); i++)
        {
            while (!st.empty() && T[i] > T[st.top()])
            {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end
