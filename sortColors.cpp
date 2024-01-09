// Problem: https://leetcode.com/problems/sort-colors
// Solution: 


#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& colors) {
    int lo = 0, mid = 0;
    int hi = colors.size()-1;
    while(mid <= hi) {
        if(colors[mid] == 0) {
            swap(colors[mid], colors[lo]);
            lo++;
            mid++;
        }
        else if(colors[mid] == 1) {
            mid++;
        }
        else if(colors[mid] == 2) {
            swap(colors[mid], colors[hi]);
            hi--;
        }
    }
}



int main() {
    int n;
    cin >> n;
    vector<int> colors(n);
    for(int i = 0; i < n; i++)
        cin >> colors[i];
    sortColors(colors);
    for(int i = 0; i < n; i++)
        cout << colors[i] << " ";
    return 0;
}