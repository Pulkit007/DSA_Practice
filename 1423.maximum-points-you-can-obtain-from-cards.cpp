/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        vector<int> pre(n);
        pre[0] = cardPoints[0];
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] + cardPoints[i];
        }
        if (k == n)
        {
            return pre[n - 1];
        }
        int ans = pre[n - 1] - pre[n - k - 1];
        for (int i = 0; i < k; i++)
        {
            int f = pre[i];
            int s = pre[n - 1] - pre[n - k + i];
            ans = max(ans, f + s);
        }
        return ans;
    }
};
// @lc code=end
