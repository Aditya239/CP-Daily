class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>m;
        int maxi = INT_MIN;
        int maxElement;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for (auto i : m)
        {
            if (maxi < i.second)
            {
                maxi = i.second;
                maxElement = i.first;
            }
        }
        return maxElement;
    }
};