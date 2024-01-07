// Problem: https://leetcode.com/problems/next-permutation
// Solution: 
//  1. Brute force approach is to find all the permuations and compare them, this will take O(n!) TC.
//  2. We need to find the breakpoint of the array from back such that arr[i] <= arr[i+1], 
//     as the right part of the array can not be rearranged to find next larger (because it is in descending order).
//  3. If we find such a breakpoint, we need to find the smallest element greater than arr[i] 
//     in the right part of breakpoint such that arr[i] < arr[j] (Here we can use the info 
//     that the first element we encounter while traversing from backwards, that is greater than breakpoint, 
//     we can swap it with the breakpoint, as the right part is in descending order)
//  4. Now we need to reverse the right part of the breakpoint
//  5. If we don't find such breakpoint, we return the reverse of the array as it is not possible to find the next larger permutation
//  6. This approach will take O(n) TC and O(1) SC.
// Note:
//  This problem is based on pattern observation, you need to take multiple examples to understand it, and if you don't understand it, 
//  you can check the approach and try to implement and then understand it.




#include <bits/stdc++.h>
using namespace std;

void findNextLarger(vector<int> &nums) {
    int len = nums.size();
    for(int i = len-2; i >= 0; i--) {
        if(nums[i] < nums[i+1]) {
            int j = len-1;
            while(nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
            return;
        }
    }
    reverse(nums.begin(), nums.end());
}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    findNextLarger(nums);
    for(int i = 0; i < n; i++)
        cout << nums[i] << " ";
    return 0;
}