/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1, ans = 0;
        while (l < r)
        {
            int water = min(height[l], height[r]) * (r - l);
            ans = max(ans, water);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
// @lc code=end
