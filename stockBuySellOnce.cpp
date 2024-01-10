// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Solution: 
//  1. Brute force approach is to take consider the current idx to be buying price
//     and all the next elements to be selling price. We will track the max profit
//     in the whole process and return it. This will take O(n^2) TC and O(1) SC.
// 2. The optimal approach is to traverse the array and keep track of the min element,
//    if the current element is lower than min element, we update min element else, 
//    we calculate the profit and update max profit. This will take O(n) TC and O(1) SC.


#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int len = prices.size();
    int profit = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < len; i++) {
        if(minPrice > prices[i])
            minPrice = prices[i];
        else
            profit = max(profit, prices[i]-minPrice);
    }
    return profit;
}



int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++)
        cin >> prices[i];
    int profit = maxProfit(prices);
    cout << profit << endl;
    return 0;
}