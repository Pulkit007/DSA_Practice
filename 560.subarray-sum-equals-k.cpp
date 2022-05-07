/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        map<int, int> mp;
        mp[0] = 1;
        int curr = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curr += nums[i];
            int req = curr - k;
            if (mp.find(req) != mp.end())
            {
                ans += mp[req];
            }
            mp[curr]++;
        }
        return ans;
    }
};
// @lc code=end
