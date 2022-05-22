/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
class Solution
{
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int maxDistance(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                }
            }
        }

        if (q.size() == n * m)
            return -1;

        int dist = 0;
        while (!q.empty())
        {
            int sz = q.size();
            dist++;
            for (int i = 0; i < sz; i++)
            {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int xx = x + dx[k];
                    int yy = y + dy[k];

                    if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == 0)
                    {
                        q.push({xx, yy});
                        grid[xx][yy] = 1;
                    }
                }
            }
        }
        return dist - 1;
    }
};
// @lc code=end
