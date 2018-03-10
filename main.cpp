#include <bits/stdc++.h>
using namespace std;
/*
*/

typedef long long ll;
int coins[10];
int dp[3][1000000];
int n;
ll solve(int cur, int tot) {
    if(tot > n) {
        return 0;
    }
    if(cur == 3) {
        return (tot == n);
    }
    if(dp[cur][tot] != -1) {
        return dp[cur][tot];
    }
    ll ret = 0;
    for(int i = 0; i <= n / coins[cur]; i++) {
        ret += solve(cur + 1, tot + (i * coins[cur]));
    }
    return dp[cur][tot] = ret;
}
int main() {
    int t;
    while(cin >> t) {
        n = t - 1;
        coins[0] = 1;
        coins[1] = 2;
        coins[2] = ceil(max(1,n) / 3.0);
        memset(dp, -1, sizeof(dp));
        int tmp = solve(0, 0);
        if(tmp != t) {
            cout << n << ' ' << coins[2] << ' ' << tmp << endl;
        }
    }
    return 0;
}   