class Solution {
public:
    vector<int> incl;
    vector<int> excl;
    int robber(vector<int>& numbers, int limit, bool include){
        if(limit == 0 && include)
            return numbers[0];
        else if(limit == 0)
            return 0;
        else if(include){
            if(incl[limit] > -1)
                return incl[limit];
            int answer = robber(numbers, limit-1, false) + numbers[limit];
            incl[limit] = answer;
            return answer;
        }
        if(excl[limit] > -1)
            return excl[limit];
        int answer = max(robber(numbers, limit-1, true), robber(numbers, limit-1, false));
        excl[limit] = answer;
        return answer;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        for(int j=0; j<nums.size(); j++){
            incl.push_back(-1);
            excl.push_back(-1);
        }
        return max(robber(nums, nums.size()-1, true), robber(nums, nums.size()-1, false));
    }
};
