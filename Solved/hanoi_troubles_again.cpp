#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    long long dp[51];
    dp[1] = 1;
    for(int i = 2; i <= 50; i++) {
        dp[i] = i + dp[i-1] + (i%2);
    }
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}