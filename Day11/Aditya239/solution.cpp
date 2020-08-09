class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
            return intervals;
        sort(intervals.begin(), intervals.end(), \
             [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
        vector<int> currint = intervals[0];
        vector<vector<int>> answer;
        for(vector<vector<int>>::iterator it = intervals.begin()+1; it != intervals.end(); ++it)
        {
            if((*it)[0] > currint[1]){
                answer.push_back(currint);
                currint = *it;
            }
            else if((*it)[1] >= currint[1])
                currint[1] = (*it)[1];
        }
        answer.push_back(currint);
        return answer;
    }
};
