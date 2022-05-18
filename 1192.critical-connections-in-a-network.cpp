/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<vector<int>> ans;
    int timer = 0;

    void dfs(int u, int p)
    {
        disc[u] = low[u] = ++timer;
        for (auto &v : adj[u])
        {
            if (v == p)
                continue;
            if (disc[v] == -1)
            {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u])
                {
                    ans.push_back({u, v});
                }
            }
            else
            {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        adj.resize(n);
        disc.resize(n, -1);
        low.resize(n);

        for (auto &connection : connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        timer = 0;
        for (int i = 0; i < n; i++)
        {
            if (disc[i] == -1)
                dfs(i, -1);
        }
        return ans;
    }
};
// @lc code=end
