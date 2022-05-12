/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                s1.push(s[i]);
            }
            else
            {
                if (s1.size() > 0)
                {
                    char p = s1.top();
                    if (s[i] == ')' && p != '(')
                    {
                        return false;
                    }
                    else if (s[i] == '}' && p != '{')
                    {
                        return false;
                    }
                    else if (s[i] == ']' && p != '[')
                    {
                        return false;
                    }
                    s1.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (s1.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end

