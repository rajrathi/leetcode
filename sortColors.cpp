// Problem: https://leetcode.com/problems/sort-colors
// Solution: 
//   1. Brute force approach is to sort the array and return it. This will take O(nlogn) TC and O(1) SC.
//   2. Optimal approach is based on Dutch National Flag algorithm.
//   3. You can take hint from how we solve "Segregate 0s and 1s in an array", We use two pointers there lo and hi.
//   4. Similarly, here we have to use three pointers, lo, mid, hi. Here lo will be used to place 0 in the lower part of the array,
//      mid will be used to traverse the array, and hi will be used to place 2 in the higher part of the array.
//   5. This alagorithm works like such that, if mid == 0, you swap with lo and increment lo and mid. If you mid == 1, 
//      then you increment mid and do nothing, and if mid == 2, you swap wit hi and decrement hi. 
//      (We don't increment the mid when we encounter 2 because the element we are swapping it with is unprocessed.)


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