class Solution {
public:
    int reduceSquares(vector<vector<int>>& bigmatrix, int rowsnum, int colsnum){
        int suma = 0;
        for(int row=0; row < rowsnum; row++){
            for(int col=0; col < colsnum; col++){
                if(bigmatrix[row][col]==1 && bigmatrix[row+1][col]==1 && \
                   bigmatrix[row][col+1]==1 && bigmatrix[row+1][col+1]==1)
                    bigmatrix[row][col] = 1;
                else
                    bigmatrix[row][col] = 0;
                suma += bigmatrix[row][col];
            }
        }
        return suma;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int rowsnum = matrix.size();
        int colsnum = matrix[0].size();
        int answer = accumulate(matrix.begin(), matrix.end(), 0, \
                                [](int init, const vector<int>& intvec)\
                                {return accumulate(intvec.begin(), intvec.end(), init);});
        while((rowsnum > 1) && (colsnum > 1))
            answer += reduceSquares(matrix, --rowsnum, --colsnum);
        return answer;
    }
};
