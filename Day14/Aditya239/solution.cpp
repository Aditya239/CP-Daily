class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        vector<vector<vector<int> > > answer(mat.size(), vector<vector<int> >(mat[0].size(), vector <int>(mat[0].size() , 0)));
        int total = 0;
        int ones = 0;
        for(int j=0; j<answer[0].size(); j++){
            if(mat[0][j]==1){
                fill_n(answer[0][j].begin(), ++ones, 1);
                total += ones;
            }
            else
                ones = 0;
        }
        ones = answer[0][0][0];
        for(int j=1; j<answer.size(); j++){
            if(mat[j][0]==1){
                answer[j][0][0] = ++ones;
                total += ones;
            }
            else
                ones = 0;
        }
        for(int i=1; i<answer.size(); i++){
            for(int j=1; j<answer[0].size(); j++){
                if(mat[i][j]==0)
                    continue;
                answer[i][j][0] = answer[i-1][j][0] + 1;
                for(int k=0; k<answer[i][j-1].size() && answer[i][j-1][k]>0; k++)
                    answer[i][j][k+1] = min(answer[i][j-1][k], answer[i-1][j][k+1]+1);
                total = accumulate(answer[i][j].begin(), answer[i][j].end(), total);
            }
        }
        return total;
    }
};
