/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = needle.size();
        int m = haystack.size();
        for (int i = 0; i < m - n + 1; i++)
        {
            string temp = haystack.substr(i, n);
            if (temp == needle)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
