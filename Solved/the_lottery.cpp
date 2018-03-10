#include <bits/stdc++.h>
using namespace std;
int gcd(long long a, long long b) {
    if(!b) {
        return a;
    }
    return gcd(b, a%b);
}
long long lcm(long long a, long long b) {
    return (a*b)/gcd(a,b);
}
int main() {
    int n,m;
    while(cin >> n >> m) {
        long long actual[m];
        for(int i = 0; i < m; i++) {
            cin >> actual[i];
        }
        sort(actual, actual + m);
        long long cur = n;
        for(int i = 1; i <= (1 << m)-1; i++) {
            long long tmp = -1;
            for(int j = 0; j < m; j++) {
                if(i & (1 << j)) {
                    if(tmp == -1) {
                        tmp = actual[j];
                    }
                    else {
                        tmp = lcm(tmp, actual[j]);
                    }
                }
            }
            if(__builtin_popcount(i) % 2) {
                cur -= (n / tmp);
            }
            else {
                cur += (n / tmp);
            }
        }
        cout << cur << endl;
    }
    return 0;
}