/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return true;
        if (nums[0] == 0)
            return false;

        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                mx = max(mx, i + nums[i]);
            }
            else
            {
                if (mx <= i && i != n - 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
