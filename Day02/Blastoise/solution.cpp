class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>dp(m, vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j] = mat[i][j];
                }
                else if(i==0)
                {
                    dp[i][j] = dp[i][j-1] + mat[i][j];
                }
                else if(j==0)
                {
                    dp[i][j] = dp[i-1][j]+mat[i][j];
                }
                else{
                    dp[i][j] = dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+mat[i][j];
                }
            }
        }
        
        
        vector<vector<int>>ans(m, vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i+k<m && j+k<n)
                {
                    ans[i][j] = dp[i+k][j+k];
                    if(i-k-1>=0){
                        ans[i][j] -= dp[i-k-1][j+k];
                    }
                    if(j-k-1>=0){
                        ans[i][j] -= dp[i+k][j-k-1];
                    }
                    if(j-k-1 >= 0 && i-k-1 >= 0){
                        ans[i][j] += dp[i-k-1][j-k-1];
                    }
                }
                else if(i+k<m && j+k>=n){
                    ans[i][j] = dp[i+k][n-1];
                    if(i-k-1>=0){
                        ans[i][j] -= dp[i-k-1][n-1];
                    }
                    if(j-k-1>=0){
                        ans[i][j] -= dp[i+k][j-k-1];
                    }
                    if(j-k-1 >= 0 && i-k-1 >= 0){
                        ans[i][j] += dp[i-k-1][j-k-1];
                    }
                }
                else if(i+k>=m && j+k<n){
                    ans[i][j] = dp[m-1][j+k];
                    if(i-k-1>=0){
                        ans[i][j] -= dp[i-k-1][j+k];
                    }
                    if(j-k-1>=0){
                        ans[i][j] -= dp[m-1][j-k-1];
                    }
                    if(j-k-1 >= 0 && i-k-1 >= 0){
                        ans[i][j] += dp[i-k-1][j-k-1];
                    }
                }
                else{
                    ans[i][j] = dp[m-1][n-1];
                    if(i-k-1>=0){
                        ans[i][j] -= dp[i-k-1][n-1];
                    }
                    if(j-k-1>=0){
                        ans[i][j] -= dp[m-1][j-k-1];
                    }
                    if(j-k-1 >= 0 && i-k-1 >= 0){
                        ans[i][j] += dp[i-k-1][j-k-1];
                    }
                }
            }
        }
        
        return ans;
        
    }
};
