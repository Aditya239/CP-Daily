class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        vector<int> vec;
        int answer = 0;
        int previdx = - S - 1;
        int zerosofar = 0;
        for(int j = 0; j < A.size(); j++){
            if(A[j]==1){
                vec.push_back(zerosofar+1);
                if(++previdx >= 0){
                    if(S > 0)
                        answer += vec[previdx]*vec[previdx+S];
                    else
                        answer += (vec[previdx]*(vec[previdx]-1))/2;
                }
                zerosofar = 0;
            }
            else
                zerosofar++;
        }
        vec.push_back(zerosofar+1);
        if(++previdx >= 0){
            if(S > 0)
                answer += vec[previdx]*vec[previdx+S];
            else
                answer += (vec[previdx]*(vec[previdx]-1))/2;
        }
        return answer;
    }
};
