/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int ans = merge(nums, 0, nums.size() - 1);
        return ans;
    }
    int merge(vector<int> &nums, int s, int e)
    {
        if (s >= e)
            return 0;

        int mid = (s + e) / 2;
        int c = merge(nums, s, mid) + merge(nums, mid + 1, e);
        for (int i = s, j = mid + 1; i <= mid; i++)
        {
            while (j <= e && nums[i] / 2.0 > nums[j])
                j++;
            c += j - mid - 1;
        }
        sort(nums.begin() + s, nums.begin() + e + 1);
        return c;
    }
};
// @lc code=end
