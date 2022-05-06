/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if (rem == 0)
                ans++;
            if (rem < 0)
                rem += k;
            if (mp.find(rem) != mp.end())
                ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};
// @lc code=end
