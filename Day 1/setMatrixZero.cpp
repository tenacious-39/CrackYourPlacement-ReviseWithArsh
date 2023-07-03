/* Brute Force*/
class Solution {
public:
/*
Approach: Use 2 dummy arrays, roe and col. Now, while traversing if matrix[i][j]
is 0, set row[i] and col[j] as 0. Again trverse the matrix and set matrix[i][j], 0
if row[i] == 0 || col[j] == 0.

TC -> O(N^2), SC -> O(2*N)
*/
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row(n, -1), col(m, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!row[i] or !col[j]){
                    matrix[i][j] =0;
                }
            }
         }
    }
};




/*Optimal Approach*/
class Solution {
public:
/*
Optimal Approach: Use matrix[i][0] and matrix[0][j], as the two dummy array row and col.
Use a variable col0 to indicate if matrix[0][0] contains 0.
While setting matrix[i][j] to 0, remember to traverse from the back.

TC -> O(N^2), SC -> O(1)
*/
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int col0=1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j == 0) col0 = 0;
                    else{
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 1; j--){
                if(!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j] = 0;
                }
            }
            if(col0 == 0) matrix[i][0] = 0;
        }
    }
};
