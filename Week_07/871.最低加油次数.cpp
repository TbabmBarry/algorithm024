/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */

// @lc code=start
class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        if (stations.size() == 0 && startFuel < target)
        {
            return -1;
        }
        priority_queue<int> max_heap;
        stations.push_back(vector<int>{target, 0});
        int res = 0, pre_loc = 0;
        for (const auto &s : stations)
        {
            int loc = s[0];
            int fuel = s[1];
            startFuel -= loc - pre_loc;
            while (startFuel < 0 && !max_heap.empty())
            {
                startFuel += max_heap.top();
                max_heap.pop();
                res++;
            }
            if (startFuel < 0)
                return -1;
            max_heap.push(fuel);
            pre_loc = loc;
        }
        return res;
    }
};
// @lc code=end
