class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
        {
            return false;
        }
        int n = matrix[0].size();
        int ul;
        int li;
        int middle;
        for (int i = 0; i < m; i++)
        {
            ul = n - 1;
            li = 0;
            while (ul >= li && ul >= 0)
            {
                middle = (ul + li) / 2;

                if (matrix[i][middle] == target)
                {
                    return true;
                }
                else if (matrix[i][middle] > target)
                {
                    ul = middle - 1;
                }
                else {
                    li = middle + 1;
                }
            }
        }
        return false;
    }
};