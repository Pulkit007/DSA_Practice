class Solution
{
public:
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j, int n, int m)
    {
        vis[i][j] = true;
        grid[i][j] = '#';

        if (i - 1 >= 0 && grid[i - 1][j] == 'O' && vis[i - 1][j] == false)
        {
            dfs(grid, vis, i - 1, j, n, m);
        }
        if (i + 1 < n && grid[i + 1][j] == 'O' && vis[i + 1][j] == false)
        {
            dfs(grid, vis, i + 1, j, n, m);
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 'O' && vis[i][j - 1] == false)
        {
            dfs(grid, vis, i, j - 1, n, m);
        }
        if (j + 1 < m && grid[i][j + 1] == 'O' && vis[i][j + 1] == false)
        {
            dfs(grid, vis, i, j + 1, n, m);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                {
                    if (mat[i][j] == 'O' && vis[i][j] == false)
                    {
                        dfs(mat, vis, i, j, n, m);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == '#')
                {
                    mat[i][j] = 'O';
                }
                else if (mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};