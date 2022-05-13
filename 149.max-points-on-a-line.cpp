/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution
{
public:
    int maxPoints(vector<vector<int>> &p)
    {
        int ans = 0;
        int n = p.size();
        for (int i = 0; i < n; i++)
        {
            unordered_map<double, int> mp;
            int same = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (p[i][0] == p[j][0] && p[i][1] == p[j][1])
                {
                    same++;
                }
                else if (p[i][0] == p[j][0])
                {
                    mp[INT_MAX]++;
                }
                else
                {
                    double slope = double(p[i][1] - p[j][1]) / double(p[i][0] - p[j][0]);
                    mp[slope]++;
                }
            }

            int cnt = 0;
            for (auto j : mp)
            {
                cnt = max(cnt, j.second);
            }
            cnt += same;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
// @lc code=end
