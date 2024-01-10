// Problem: https://leetcode.com/problems/merge-intervals
// Solution: 


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) {
    vector<vector<int>> merged;
    sort(intervals.begin(), intervals.end());
    vector<int> interval = intervals[0];
    for(int i = 1; i < intervals.size(); i++) {
        if(interval[1] >= intervals[i][0]) {
            interval[1] = max(interval[1], intervals[i][1]);
        }
        else {
            merged.push_back(interval);
            interval = intervals[i];
        }
    }
    merged.push_back(interval);
    return merged;
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i = 0; i < n; i++)
        cin >> intervals[i][0] >> intervals[i][1];
    vector<vector<int>> ans = mergeIntervals(intervals);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}