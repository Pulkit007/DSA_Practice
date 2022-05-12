/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int n = a.length(), m = b.length();
        int i = n - 1, j = m - 1;
        int carry = 0;
        string ans = "";
        while (i >= 0 && j >= 0)
        {
            int s = (a[i] - '0') + (b[j] - '0') + carry;
            if (s == 2)
            {
                ans += '0';
                carry = 1;
            }
            else if (s == 3)
            {
                ans += '1';
                carry = 1;
            }
            else if (s == 1)
            {
                ans += '1';
                carry = 0;
            }
            else
            {
                ans += '0';
                carry = 0;
            }
            i--;
            j--;
        }

        while (i >= 0)
        {
            int s = a[i] - '0' + carry;
            if (s == 2)
            {
                ans += '0';
                carry = 1;
            }
            else if (s == 3)
            {
                ans += '1';
                carry = 1;
            }
            else if (s == 1)
            {
                ans += '1';
                carry = 0;
            }
            else
            {
                ans += '0';
                carry = 0;
            }
            i--;
        }

        while (j >= 0)
        {
            int s = b[j] - '0' + carry;
            if (s == 2)
            {
                ans += '0';
                carry = 1;
            }
            else if (s == 3)
            {
                ans += '1';
                carry = 1;
            }
            else if (s == 1)
            {
                ans += '1';
                carry = 0;
            }
            else
            {
                ans += '0';
                carry = 0;
            }
            j--;
        }
        if (carry > 0)
            ans = ans + to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
