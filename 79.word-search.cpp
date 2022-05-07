/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution
{
public:
    bool dfs(vector<vector<char>> &board, int i, int j, string &word)
    {
        if (!word.size())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
        {
            return false;
        }

        char c = word[0];
        string temp = word.substr(1);
        board[i][j] = '*';
        bool flag = dfs(board, i + 1, j, temp) || dfs(board, i - 1, j, temp) || dfs(board, i, j + 1, temp) || dfs(board, i, j - 1, temp);
        board[i][j] = c;
        return flag;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, i, j, word))
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
