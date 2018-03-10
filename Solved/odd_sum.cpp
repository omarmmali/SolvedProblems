#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++) {
        int l,r;
        scanf("%d %d", &l, &r);
        r = (r + 1) / 2;
        l = l / 2;
        printf("Case %d: %d\n", tc, (r * r) - (l * l));
    }
    return 0;
}