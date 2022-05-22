/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 */

// @lc code=start
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (auto ed : edges)
        {
            int u = ed[0];
            int v = ed[1];
            int wt = ed[2];
            dp[u][v] = wt;
            dp[v][u] = wt;
        }

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 0;
        }

        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (dp[i][k] < INT_MAX && dp[k][j] < INT_MAX)
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        int mx = INT_MAX, city = -1;
        for (int i = 0; i < n; i++)
        {
            int c = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (dp[i][j] <= distanceThreshold)
                {
                    c++;
                }
            }
            if (mx >= c)
            {
                city = i;
                mx = c;
            }
        }

        return city;
    }
};
// @lc code=end
