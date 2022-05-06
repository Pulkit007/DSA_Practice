/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> vp;
        for (int i = 0; i < nums.size(); i++)
        {
            vp.push_back(make_pair(nums[i], i));
        }
        sort(vp.begin(), vp.end());
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            if (vp[l].first + vp[r].first == target)
            {
                return {vp[l].second, vp[r].second};
            }
            else if (vp[l].first + vp[r].first < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return {};
    }
};
// @lc code=end
