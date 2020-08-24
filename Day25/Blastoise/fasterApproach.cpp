class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K)
    {
        vector<long>distance(points.size());
        vector<vector<int>>answer(K);
        int index = 0;
        for (int i = 0; i < points.size(); i++)
        {
            distance[i] = 1LL * points[i][0] * points[i][0] + 1LL * points[i][1] * points[i][1];
        }
        sort(distance.begin(), distance.end());
        for (int i = 0; i < points.size(); i++)
        {
            if (1LL * points[i][0]*points[i][0] + 1LL * points[i][1]*points[i][1] <= distance[K - 1])
            {
                answer[index].push_back(points[i][0]);
                answer[index].push_back(points[i][1]);
                index++;
            }
            if (index == K)
            {
                break;
            }
        }
        return answer;
    }
};