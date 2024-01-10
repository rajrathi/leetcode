// Problem: https://leetcode.com/problems/rotate-image
// Solution: 
//  1. The brtute approach to rotate the image will take O(n^2) TC and O(n^2) SC.
//  2. But to do it inplace, we can use the observation that if you take transpose
//     of the matrix and then reverse the rows of the matrix, the matrix will be rotated
//     by 90 degrees.

#include <bits/stdc++.h>
using namespace std;

void rotateImage(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i < j) {
                // taking the transpose of matrix
                int temp = matrix[i][j];
                matrix[i][j] =  matrix[j][i];
                matrix[j][i] =  temp;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        // reverse the rows of matrix
        reverse(matrix[i].begin(), matrix[i].end());
    }
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    rotateImage(matrix);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}