/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution
{
public:
    vector<string> ans;
    void recur(int in, int out, string &k, int n)
    {
        if (k.size() == 2 * n && in == out)
        {
            ans.push_back(k);
            return;
        }

        if (in < n)
        {
            k += '(';
            recur(in + 1, out, k, n);
            k.pop_back();
        }
        if (in > out && out < n)
        {
            k += ')';
            recur(in, out + 1, k, n);
            k.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        int in = 0, out = 0;
        string k = "";
        recur(in, out, k, n);
        return ans;
    }
};
// @lc code=end
