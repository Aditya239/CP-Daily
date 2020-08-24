class Solution {
public:

    void merge(vector<vector<int>>& points, int l, int middle, int r)
    {
        vector<vector<int>>left(middle - l + 1);
        vector<vector<int>>right(r - middle);
        int k = 0;
        for (int i = l; i <= middle; i++)
        {
            left[k].push_back(points[i][0]);
            left[k].push_back(points[i][1]);
            k++;
        }
        k = 0;
        for (int i = middle + 1; i <= r; i++)
        {
            right[k].push_back(points[i][0]);
            right[k].push_back(points[i][1]);
            k++;
        }

        int j = 0, i = 0;
        int index = l;
        long long int a, b;
        while (j <= right.size() - 1 && i <= left.size() - 1)
        {
            a = 1LL * left[i][0] * left[i][0] + 1LL * left[i][1] * left[i][1];
            b = 1LL * right[j][0] * right[j][0] + 1LL * right[j][1] * right[j][1];
            if (a > b)
            {
                points[index][0] = right[j][0];
                points[index][1] = right[j][1];
                j++;
                index++;
            }
            else {
                points[index][0] = left[i][0];
                points[index][1] = left[i][1];
                i++;
                index++;
            }
        }
        while (i <= left.size() - 1)
        {
            points[index][0] = left[i][0];
            points[index][1] = left[i][1];
            i++;
            index++;
        }
        while (j <= right.size() - 1)
        {
            points[index][0] = right[j][0];
            points[index][1] = right[j][1];
            j++;
            index++;
        }
    }

    void mergeSort(vector<vector<int>>& points, int l, int r)
    {
        if (l >= r)
        {
            return;
        }
        int middle = (l + r) / 2;

        mergeSort(points, l, middle);
        mergeSort(points, middle + 1, r);

        merge(points, l, middle, r);

    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        mergeSort(points, 0, points.size() - 1);
        vector<vector<int>>v(K);
        for (int i = 0; i < K; i++)
        {
            v[i].push_back(points[i][0]);
            v[i].push_back(points[i][1]);
        }
        return v;
    }
};