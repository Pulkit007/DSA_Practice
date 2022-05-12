/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
        {
            return strs[0];
        }
        string ans = "";
        bool p = true;
        bool q = false;
        for (int i = 0; i < 200; i++)
        {
            for (int j = 0; j < strs.size() - 1; j++)
            {
                if (strs[j].length() <= i)
                {
                    q = true;
                    return ans;
                }
                if (strs[j][i] != strs[j + 1][i])
                {
                    p = false;
                    break;
                }
            }
            if (p == true)
            {
                ans += strs[0][i];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
