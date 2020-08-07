class Solution {
public:

    pair<int, int> dp[40][40];
    void initialize()
    {
        for (int i = 0; i < 40; i++)
        {
            for (int j = 0; j < 40; j++)
            {
                dp[i][j] = { -1, -1};
            }
        }
    }

    pair<int, int> answer(vector<int>& arr, int left, int right)
    {
        pair<int, int>mini;
        if (dp[left][right].first != -1)
        {
            return dp[left][right];
        }
        if (left == right)
        {
            dp[left][right] = make_pair(arr[left], 0);
            return dp[left][right];
        }

        if (right - left + 1 == 2)
        {
            pair<int, int>
            g2 = make_pair(max(arr[left], arr[right]), arr[left] * arr[right]);
            dp[left][right] = g2;
            return g2;
        }
        else {

            for (int i = 1; i < right - left + 1; i++)
            {
                pair<int, int>leftTree = answer(arr, left, left + i - 1);
                pair<int, int>rightTree = answer(arr, left + i, right);
                pair<int, int>ans(max(leftTree.first, rightTree.first), leftTree.second + rightTree.second + (rightTree.first * leftTree.first));
                if (i == 1)
                {
                    mini.first = ans.first;
                    mini.second = ans.second;
                }
                else if (ans.second < mini.second)
                {
                    mini.second = ans.second;
                }
            }

        }
        dp[left][right] = mini;
        return mini;

    }


    int mctFromLeafValues(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        initialize();
        return answer(arr, left, right).second;
    }
};