/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    int v1 = nums[l];
                    while (l < r && nums[l] == v1)
                    {
                        l++;
                    }

                    int v2 = nums[r];
                    while (l < r && nums[r] == v2)
                    {
                        r--;
                    }
                }
                else if (nums[i] + nums[l] + nums[r] > 0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
