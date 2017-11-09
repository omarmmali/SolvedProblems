#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    if((n > m && n - m > 1) || (n < m && (((m+1) / 2) - 1) > n)) {
        cout << -1;
    }
    else {
        int z = n, w = m;
        string out;
        for(int i = 0; i < min(n,m); i++, z--) {
            out += "0";
            for(int j = 0; w && j < min(2, (int)ceil(w / (double)z)); j++) {
                out += "1";
            }
            w -= min(2,(int)(ceil(w / (double)z)));
        }
        for(int i = 0; i < w; i++) {
            out.insert(out.begin(), '1');
        }
        if(z) {
            out += '0';
        }
        cout << out << endl;
    }
    cout << endl;
    return 0;
}