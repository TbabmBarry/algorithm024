/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution
{
private:
    int father[210];
    int n;

    void init()
    {
        for (int i = 0; i < n; i++)
        {
            father[i] = i;
        }
    }

    int find(int u)
    {
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        father[v] = u;
    }

    bool same(int u, int v)
    {
        u = find(u);
        v = find(v);
        return u == v;
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        n = isConnected.size();
        init();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j])
                    join(i, j);
            }
        }
        unordered_set<int> uset;
        for (int i = 0; i < n; i++)
        {
            uset.insert(find(i));
        }
        return uset.size();
    }
};
// @lc code=end
