class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int sumTillNow = nums[0];
        for(int i=1;i<nums.size();i++){
            if(sumTillNow+nums[i]<nums[i])
            {
                sumTillNow = nums[i];   
            }
            else{
                sumTillNow+=nums[i];
                cout<<sumTillNow<<endl;
            }
            if(sumTillNow>sum)
            {
                sum = sumTillNow;
            }
        }
        
        return sum;
    }
};