// Problem: https://leetcode.com/problems/maximum-subarray/
// Solution: 
//  1. Brute force approach is to find all the subarrays and compare them, this will take O(n^2) TC.
//  2. Optimal approach is based on the prinicple, that if the sum becomes negative,
//     then adding a new number into that subarray will only result in lower value sum.
//     eg: let's say current sum = -4 at a[i], a[i+1] = 2, then we should discard the 
//     current sum and start the new subarray/sum from a[i+1] i.e. 2
//  3. Until currentSum is postive we can add the next element in the subarray, and keep track of maxSum,
//  4. If the sum becomes negative, we discard that sum/subarray and start from nextElement, but also keep 
//     track of maxSum, in case every element is negative in array. (the smallest negative number will be maxSum, if all numbers are negative)


#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    int maxSum = INT_MIN;
    int sum = INT_MIN;
    for(int i = 0; i < len; i++) {
        if(sum < 0) {
            sum = nums[i];
        }
        else {
            sum += nums[i];
        }
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) 
        cin >> nums[i];
    int ans = maxSubArray(nums);
    cout << ans << endl;
    return 0;
}