class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>a;
        if (intervals.size() == 0)
        {
            return a;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
        vector<int> compare = intervals[0];
        vector<int> temp = intervals[0];
        int maxi;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= compare[0] && intervals[i][0] <= compare[1])
            {
                maxi = (compare[1] > intervals[i][1]) ? compare[1] : intervals[i][1];
                temp = {compare[0], maxi};
                compare = temp;
            }
            else {
                a.push_back(temp);
                compare = intervals[i];
                temp = intervals[i];
            }
        }
        a.push_back(temp);
        return a;
    }
};