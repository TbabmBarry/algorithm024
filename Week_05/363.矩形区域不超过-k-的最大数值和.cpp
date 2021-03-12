/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */

// @lc code=start
class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size();
        if (m == 0 || matrix[0].size() == 0)
            return 0;
        int n = matrix[0].size();

        int res = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            vector<int> rowSums(m, 0);
            for (int j = i; j < n; j++)
            {
                set<int> prev;
                int preSum = 0;
                for (int r = 0; r < m; r++)
                {
                    rowSums[r] += matrix[r][j];
                    preSum += rowSums[r];

                    if (preSum <= k)
                        res = max(res, preSum);

                    auto lb = prev.lower_bound(preSum - k);
                    if (lb != prev.end())
                    {
                        res = max(res, preSum - *lb);
                    }
                    prev.insert(preSum);
                }
            }
        }
        return res;
    }
};
// @lc code=end
