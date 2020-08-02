class Solution {
public:
    vector<vector<int>> matrixColSum(vector<vector<int>>& mat, int K) {
        int numrows = mat.size();
        int numcols = mat[0].size();
        vector<vector<int>> vec(numrows, vector<int> (numcols, 0));
        for(int col=0; col<numcols; col++){
            for(int row=0; row<numrows; row++){
                if(row==0){
                    int suma = 0;
                    for(int elem=0; elem<=min(K, numrows-1); elem++)
                        suma += mat[elem][col];
                    vec[row][col] = suma;
                }
                else{
                    vec[row][col] = vec[row-1][col];
                    if(row-K-1 >= 0)
                        vec[row][col] = vec[row][col] - mat[row-K-1][col];
                    if(row+K < numrows)
                        vec[row][col] = vec[row][col] + mat[row+K][col];
                }
            }
        }
        return vec;
    }
    vector<vector<int>> matrixRowSum(vector<vector<int>>& mat, int K) {
        int numrows = mat.size();
        int numcols = mat[0].size();
        vector<vector<int>> vec(numrows, vector<int> (numcols, 0));
        for(int row=0; row<numrows; row++){
            for(int col=0; col<numcols; col++){
                if(col==0){
                    int suma = 0;
                    for(int elem=0; elem<=min(K, numcols-1); elem++)
                        suma += mat[row][elem];
                    vec[row][col] = suma;
                }
                else{
                    vec[row][col] = vec[row][col-1];
                    if(col-K-1 >= 0)
                        vec[row][col] = vec[row][col] - mat[row][col-K-1];
                    if(col+K < numcols)
                        vec[row][col] = vec[row][col] + mat[row][col+K];
                }
            }
        }
        return vec;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> colsum = matrixColSum(mat, K);
        return matrixRowSum(colsum, K);
    }
};
