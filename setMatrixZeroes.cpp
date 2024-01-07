// problem = https://leetcode.com/problems/set-matrix-zeroes/
// Solution:
//  1. Use two bool arrays to track which row and column contains 0
//  2. Set the ith index of the arrays to true if we encounter 0 in ith row or ith column respectively
//  3. Use the above arrys to set whole row or column as 0 for the rows and columns which have the zeros.
#include <bits/stdc++.h>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &matrix) {
    int nRows, nCols;
    // get number of rows and columns
    nRows = matrix.size();
    nCols = matrix[0].size();
    vector<bool> rows(nRows, false);
    vector<bool> cols(nCols, false);
    for(int i = 0; i < nRows; i++) {
        for(int j = 0; j < nCols; j++) {
            // track the rows and columns which have 0
            if(matrix[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    for(int i = 0; i < nRows; i++) {
        for(int j = 0; j < nCols; j++) {
            if(rows[i] || cols[j]) {
                // if a row or column has 0, set the whole row or column to 0
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    setMatrixZeroes(matrix);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}