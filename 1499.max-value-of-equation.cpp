/*
 * @lc app=leetcode id=1499 lang=cpp
 *
 * [1499] Max Value of Equation
 */

// @lc code=start
class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, int>> pq;
        int n = points.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (pq.empty())
            {
                pq.push({points[i][1] - points[i][0], points[i][0]});
            }
            else
            {
                while (!pq.empty() && points[i][0] - pq.top().second > k)
                {
                    pq.pop();
                }
                if (!pq.empty())
                {
                    ans = max(ans, pq.top().first + points[i][1] + points[i][0]);
                }
                pq.push({points[i][1] - points[i][0], points[i][0]});
            }
        }
        return ans;
    }
};
// @lc code=end
