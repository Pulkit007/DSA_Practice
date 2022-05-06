/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int idx = abs(nums[i]) - 1;
            nums[idx] *= -1;
            if (nums[idx] > 0)
                ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};
// @lc code=end
