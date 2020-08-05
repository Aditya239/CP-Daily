class Solution {
public:
    int dp[41][41];
    int maxum[41][41];
    pair<int, int> mctSubarray(vector<int>& arr, int l, int r) {
        if(dp[l][r] != -1)
            return pair<int, int>(dp[l][r], maxum[l][r]);
        else if(l == r)
            return pair<int, int>(dp[l][r] = 0, maxum[l][r] = arr[l]);
        else if(r - l == 1)
            return pair<int, int>(dp[l][r] = arr[l]*arr[r], maxum[l][r] = max(arr[l], arr[r]));
        int ans = INT_MAX;
        int maxa = arr[r];
        for(int j=l; j<r; j++){
            pair<int, int> l_tree  = mctSubarray(arr, l, j);
            pair<int, int> r_tree = mctSubarray(arr, j+1, r);
            ans = min(ans, l_tree.first + r_tree.first + l_tree.second*r_tree.second);
            maxa = max(maxa, arr[j]);
        }
        return pair<int, int>(dp[l][r] = ans, maxum[l][r] = maxa);
    }
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp,    -1, sizeof(dp));
        memset(maxum, -1, sizeof(dp));
        return mctSubarray(arr, 0, arr.size()-1).first;
    }
};
