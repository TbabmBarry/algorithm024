/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution
{
public:
    int count = 0;
    int totalNQueens(int n)
    {
        calNQueens(n, 0, 0, 0, 0);
        return count;
    }

    void calNQueens(int n, int row, int col, int ld, int rd)
    {
        if (row == n)
        {
            count++;
            return;
        }
        int pos = ~(col | ld | rd) & ((1 << n) - 1);
        while (pos)
        {
            int pick = (pos & -pos);
            calNQueens(n, row + 1, (col | pick), (ld | pick) << 1, (rd | pick) >> 1);
            pos &= (pos - 1);
        }
        return;
    }
};
// @lc code=end
