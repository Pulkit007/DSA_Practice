/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 */

// @lc code=start
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        // p - moves  final element - x
        // sum + p * (n - 1) = n * x
        // x = p + min_element
        // sum + p * n - p = n * p + n * min_element
        // sum - n * min_element = p
        int sum = 0;
        int mn = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            mn = min(mn, nums[i]);
        }
        int p = sum - n * mn;
        return p;
    }
};
// @lc code=end
