// Problem: https://leetcode.com/problems/find-the-duplicate-number
// Solution: 


#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < len-1; i++) {
        if(nums[i] == nums[i+1])
            return nums[i];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n+1);
    for(int i = 0; i < n+1; i++)
        cin >> nums[i];
    int duplicate = findDuplicate(nums);
    cout << duplicate << endl;
    return 0;
}