// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Solution: 


#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int len = prices.size();
    int profit = 0;
    int minPrice = INT_MAX, maxPrice = INT_MIN;
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