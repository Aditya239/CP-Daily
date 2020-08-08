class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> vec(num+1, 0);
        for(int j=1; j<=num; j++)
            vec[j] = vec[j/2] + j%2;
        return vec;
    }
};
