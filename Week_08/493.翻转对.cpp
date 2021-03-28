/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        int res = 0;
        vector<int> tmp(n);
        mergeSort(nums, tmp, left, right, res);
        return res;
    }
    void mergeSort(vector<int> &nums, vector<int> &tmp, int left, int right, int &res)
    {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, tmp, left, mid, res);
        mergeSort(nums, tmp, mid + 1, right, res);

        int i = left, j = mid + 1;
        while (i <= mid && j <= right)
        {
            if ((long long)nums[i] > (long long)2 * nums[j])
            {
                res += (mid - i + 1);
                j++;
            }
            else
            {
                i++;
            }
        }

        i = left, j = mid + 1;
        int t = 0;
        while (i <= mid && j <= right)
        {
            if (nums[i] > nums[j])
            {
                tmp[t++] = nums[j++];
            }
            else
            {
                tmp[t++] = nums[i++];
            }
        }
        while (i <= mid)
        {
            tmp[t++] = nums[i++];
        }
        while (j <= right)
        {
            tmp[t++] = nums[j++];
        }
        t = 0;
        while (left <= right)
        {
            nums[left++] = tmp[t++];
        }
    }
};
// @lc code=end
