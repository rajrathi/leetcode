// Problem: https://leetcode.com/problems/powx-n
// Solution: 


#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    long long nn = n;
    if(nn < 1) nn = nn * -1;
    double ans = 1.0;
    while(nn > 0) {
        if(nn % 2 == 1) {
            ans = ans * x;
            nn -= 1;
        }
        else {
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0) 
        ans = ((double)1.0 / (double)ans);
    return ans;
}



int main() {
    double x;
    int n;
    cin >> x >> n;
    double ans = myPow(x, n);
    cout << ans << endl;
    return 0;
}