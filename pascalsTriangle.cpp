// Problem: https://leetcode.com/problems/pascals-triangle/
// Solution: 
//  1. For bruteforce approoch, we can use formula nCr = n!/(n-r)!r! for each row. 
//     But this approach will take O(n*n!) TC.
//  2. We can use here some pattern when we are calculating coefficient nCr.
//  3. for example let's say we want to calculate 5C1, we can use 5/1, for 5C2 = 5*4/2*1
//     for 5C3, we can use pattern 5*4*3/3*2*1.
//     Similary for 5C4, 5*4*3*2/4*3*2*1 and so on.
//  4. We can use this pattern to calculate coeffs for each row.
//  5. For nC0, we can always push 1 to the ith row of pascal's triangle, 
//     and afterwards, we can calculate for rest of the rows.


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascalT;
    for (int i = 0; i < numRows; i++) {
        vector<int> ithRow;
        int coeff = 1;
        ithRow.push_back(coeff);
        for(int j = i; j > 0; j--) {
            coeff = coeff * j / (i - j + 1);
            ithRow.push_back(coeff);
        }
        pascalT.push_back(ithRow);
    }
    return pascalT;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> ans = generate(n);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}