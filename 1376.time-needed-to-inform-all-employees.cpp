/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start
class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<int> g[n];
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                g[manager[i]].push_back(i);
            }
        }

        queue<int> q;
        q.push(headID);
        vector<int> time(n);
        time[headID] = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int node = q.front();
                q.pop();
                for (int child : g[node])
                {
                    time[child] = time[node] + informTime[node];
                    q.push(child);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, time[i]);
        }
        return ans;
    }
};
// @lc code=end
