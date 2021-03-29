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
        int m = matrix.size(), n = matrix[0].size(), row = matrix.size() - 1;
        for (int i = 0; i < m - 1; i++)
        {
            if (matrix[i][0] <= target && target < matrix[i + 1][0])
            {
                row = i;
                break;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (matrix[row][j] == target)
                return true;
        }
        return false;
    }
};
// @lc code=end
