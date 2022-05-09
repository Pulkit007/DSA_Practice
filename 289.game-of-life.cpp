/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution
{
public:
    int dx[3] = {-1, 0, 1};
    int dy[3] = {-1, 0, 1};
    bool isValid(int i, int j, int r, int c)
    {
        if (i >= 0 && i < r && j >= 0 && j < c)
            return true;
        return false;
    }
    int helper(vector<vector<int>> &board, int x, int y, int r, int c)
    {
        int cnt = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if ((i != j) || (i == j && i != 1))
                {
                    int xx = x + dx[i];
                    int yy = y + dy[j];
                    if (isValid(xx, yy, r, c))
                    {
                        if (board[xx][yy])
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> temp = board;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int cnt = helper(board, i, j, m, n);
                if (board[i][j] == 1)
                {
                    if (cnt < 2)
                    {
                        temp[i][j] = 0;
                    }
                    else if (cnt < 4)
                    {
                        continue;
                    }
                    else
                    {
                        temp[i][j] = 0;
                    }
                }
                else
                {
                    if (cnt == 3)
                    {
                        temp[i][j] = 1;
                    }
                }
            }
        }
        board = temp;
    }
};
// @lc code=end
