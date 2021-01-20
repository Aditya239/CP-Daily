class Solution
{
public:
    int vis[200][200];
    int dp[200][200];

    bool isValid(int i, int j, vector<vector<int>> &matrix)
    {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
        {
            return false;
        }
        return true;
    }

    int dfs(int i, int j, vector<vector<int>> &matrix)
    {
        if (vis[i][j] == 1)
        {
            return dp[i][j];
        }

        vis[i][j] = 1;
        int left = 0, right = 0, up = 0, down = 0;
        if (isValid(i, j - 1, matrix) && matrix[i][j] < matrix[i][j - 1])
        {
            left = dfs(i, j - 1, matrix);
        }

        if (isValid(i, j + 1, matrix) && matrix[i][j] < matrix[i][j + 1])
        {
            right = dfs(i, j + 1, matrix);
        }

        if (isValid(i - 1, j, matrix) && matrix[i][j] < matrix[i - 1][j])
        {
            up = dfs(i - 1, j, matrix);
        }

        if (isValid(i + 1, j, matrix) && matrix[i][j] < matrix[i + 1][j])
        {
            down = dfs(i + 1, j, matrix);
        }

        dp[i][j] = 1 + max({left, right, up, down});
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {

        int maxi = INT_MIN;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (vis[i][j] != 1)
                {
                    maxi = max(maxi, dfs(i, j, matrix));
                }
            }
        }
        return maxi;
    }
};