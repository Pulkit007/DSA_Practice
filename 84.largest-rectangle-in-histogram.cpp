/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<pair<int, int>> s;
        vector<int> left;
        for (int i = 0; i < n; i++)
        {
            if (s.size() == 0)
            {
                left.push_back(-1);
            }
            else if (s.top().first < heights[i])
            {
                left.push_back(s.top().second);
            }
            else if (s.top().first >= heights[i])
            {
                while (!s.empty() && s.top().first >= heights[i])
                {
                    s.pop();
                }

                if (s.empty())
                    left.push_back(-1);
                else
                    left.push_back(s.top().second);
            }
            s.push({heights[i], i});
        }

        while (!s.empty())
        {
            s.pop();
        }

        vector<int> right;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s.size() == 0)
            {
                right.push_back(n);
            }
            else if (s.top().first < heights[i])
            {
                right.push_back(s.top().second);
            }
            else if (s.top().first >= heights[i])
            {
                while (!s.empty() && s.top().first >= heights[i])
                {
                    s.pop();
                }

                if (s.empty())
                    right.push_back(n);
                else
                    right.push_back(s.top().second);
            }
            s.push({heights[i], i});
        }

        reverse(right.begin(), right.end());

        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            int w = right[i] - left[i] - 1;
            mx = max(mx, w * heights[i]);
        }
        return mx;
    }
};
// @lc code=end
