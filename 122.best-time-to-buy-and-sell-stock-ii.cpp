/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int cp = prices[0], ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > cp)
            {
                ans += prices[i] - cp;
                i++;
            }
            cp = prices[i];
        }
        return ans;
    }
};
// @lc code=end
