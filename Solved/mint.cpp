#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    if(!b) {
        return a;
    }
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return ((a * b) / gcd(a,b));
}
int main() {
    //freopen("output.txt", "w", stdout);
    int n,m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) {
            break;
        }
        long long coins[n];
        long long tables[m];
        for(int i = 0; i < n; i++) {
            cin >> coins[i];
        }
        long long mx = 0;
        for(int i = 0; i < m; i++) {
            cin >> tables[i];
            mx = max(mx, tables[i]);
        }
        set<long long> res;
        sort(coins, coins + n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    for(int s = k + 1; s < n; s++) {
                        long long tmp = lcm(coins[i], lcm(coins[j], lcm(coins[k], coins[s])));
                        int t = 1;
                        while(t * tmp < mx) {
                            res.insert(t * tmp);
                            t++;
                        }
                        res.insert(t * tmp);
                    }
                }
            }
        }
        for(int i = 0; i < m; i++) {
            cout << *--res.upper_bound(tables[i]) << ' ' << *res.lower_bound(tables[i]) << endl;
        }
    }
    return 0;
}