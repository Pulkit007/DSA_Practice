/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rowStart = 0, rowEnd = matrix.size() - 1, colStart = 0, colEnd = matrix[0].size() - 1;
        int i = 0, j = 0;
        bool flag = true;
        vector<int> ans;
        int f = 0;
        while (rowStart <= rowEnd && colStart <= colEnd)
        {
            if (flag == true)
            {
                if (f == 0)
                {
                    while (j <= colEnd)
                    {
                        ans.push_back(matrix[i][j++]);
                    }
                    j--;
                    rowStart++;
                    i++;
                }
                else if (f == 2)
                {
                    while (j >= colStart)
                    {
                        ans.push_back(matrix[i][j--]);
                    }
                    j++;
                    rowEnd--;
                    i--;
                }
                flag = false;
            }
            else
            {
                if (f == 1)
                {
                    while (i <= rowEnd)
                    {
                        ans.push_back(matrix[i++][j]);
                    }
                    i--;
                    colEnd--;
                    j--;
                }
                else if (f == 3)
                {
                    while (i >= rowStart)
                    {
                        ans.push_back(matrix[i--][j]);
                    }
                    i++;
                    colStart++;
                    j++;
                }
                flag = true;
            }
            f = (f + 1) % 4;
        }
        return ans;
    }
};
// @lc code=end
