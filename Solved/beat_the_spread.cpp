#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    while(n--) {
        int s, d;
        cin >> s >> d;
        if(d > s || (s + d) % 2 != 0) {
            cout << "impossible" << endl;
        }
        else {
            cout << (s + d) / 2  << ' ' << s - ((s + d) / 2) << endl;
        }
    }
    return 0;
}
