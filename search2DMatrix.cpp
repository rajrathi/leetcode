// Problem: https://leetcode.com/problems/search-a-2d-matrix/
// Solution: 


#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int lo = 0, hi = m * n - 1;
    int i, j;
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        i = mid / n;
        j = mid % n;
        if(matrix[i][j] == target) 
            return true;
        else if(target < matrix[i][j]) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return false;
}

int main() {
    int m, n;
    cin >> m >> n;
    int target;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    cin >> target;
    bool isFound = searchMatrix(matrix, target);
    cout << isFound << endl;
    return 0;
}