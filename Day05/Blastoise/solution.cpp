class Solution {
public:
    int dp[100];
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return answer(nums,nums.size()-1);
    }
    
    int answer(vector<int>& nums,int n)
    {
        if(n<0)
        {
            return 0;
        }
        else if(dp[n]!=-1)
        {
             
            return dp[n];
        }
        else{
            dp[n] = max((nums[n]+answer(nums,n-2)),answer(nums,n-1));
            
        }
        return dp[n];
    }
};