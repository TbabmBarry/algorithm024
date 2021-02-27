/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size(), col = matrix.size() - 1;
        for (int i = 0; i < m; i++)
        {
            if (i < m - 1 && matrix[i][0] <= target && target < matrix[i + 1][0])
            {
                col = i;
                break;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (matrix[col][j] == target)
                return true;
        }
        return false;
    }
};
// @lc code=end
