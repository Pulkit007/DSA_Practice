/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 1 && j < nums.size() && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1, r = nums.size() - 1;
                while (l < r)
                {
                    long long int val = (long long int)nums[i] + nums[j] + nums[l] + nums[r];
                    if (val == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});

                        int v1 = nums[l];
                        while (l < r && nums[l] == v1)
                            l++;

                        int v2 = nums[r];
                        while (l < r && nums[r] == v2)
                            r--;
                    }
                    else if (val > target)
                        r--;
                    else
                        l++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
