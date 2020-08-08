class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int answer = 0;
        for(int row=0; row<matrix.size(); row++){
            for(int col=0; col<matrix[0].size(); col++){
                if(matrix[row][col]>0 && row > 0 && col > 0)
                    matrix[row][col] = min({matrix[row-1][col-1], matrix[row][col-1], matrix[row-1][col]}) + 1;
                answer += matrix[row][col];
            }
        }
        return answer;
    }
};
