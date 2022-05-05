/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
    // 1, 0, 2, 1, 2, 0
    // 0, 0, 2, 1, 2, 1
public:
    void sortColors(vector<int> &nums)
    {
        int start = 0, mid = 0, end = nums.size() - 1;
        while (mid <= end)
        {
            if (nums[mid] == 0)
            {
                swap(nums[start++], nums[mid++]);
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid++], nums[end--]);
            }
        }
    }
};
// @lc code=end
