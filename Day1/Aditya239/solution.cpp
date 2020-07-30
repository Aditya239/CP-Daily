class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sup     = 0;
        int contsum = 0;
        int maxim   = nums[0];
        bool negpassed = false;
        for(int i=0; i<nums.size(); i++){
            maxim = max(nums[i], maxim);
            if(!negpassed && nums[i] <= 0)
                continue;
            else if(!negpassed && nums[i] > 0)
                negpassed = true;
            if(contsum + nums[i] < 0)
                contsum = 0;
            else{
                contsum += nums[i];
                sup = max(sup, contsum);
            }
        }
        if(!negpassed)
            sup = maxim;
        return sup;
    }
};