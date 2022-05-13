/*
 * @lc app=leetcode id=2242 lang=cpp
 *
 * [2242] Maximum Score of a Node Sequence
 */

// @lc code=start
class Solution
{
public:
    int maximumScore(vector<int> &scores, vector<vector<int>> &edges)
    {
        int n = scores.size();
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back({scores[edge[1]], edge[1]});
            graph[edge[1]].push_back({scores[edge[0]], edge[0]});
        }

        for (int i = 0; i < n; i++)
        {
            sort(graph[i].begin(), graph[i].end());
            while (graph[i].size() > 3)
            {
                graph[i].pop_back();
            }
        }

        int ans = 0;
        for (auto &edge : edges)
        {
            for (auto &e : graph[edge[0]])
            {
                for (auto &f : graph[edge[1]])
                {
                    if (f.second != e.second && f.second != edge[0] && e.second != edge[1])
                    {
                        ans = max(ans, e.first + f.first + scores[edge[0]] + scores[edge[1]]);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
