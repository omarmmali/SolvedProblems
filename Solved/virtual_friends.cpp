#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int>par,rnk;
    
    DSU(int n) {
        rnk.resize(n+1);
        par.resize(n+1);
        for(int i = 1; i <= n; i++) {
            rnk[i] = 1;
            par[i] = i;
        }
    }
    
    int getPar(int x) {
        return (par[x] == x ? x : par[x] = getPar(par[x]));
    }
    
    int merge(int x, int y) {
        x = getPar(x);
        y = getPar(y);
        if(x == y) {
            return rnk[x];
        }
        if(rnk[x] < rnk[y]) {
            swap(x,y);
        }
        par[y] = x;
        rnk[x] += rnk[y];
        return rnk[x];
    }
};
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<string, int> m;
        pair<string, string> q[n];
        int ind = 1;
        for(int i = 0; i < n; i++) {
            cin >> q[i].first >> q[i].second;
            if(m.find(q[i].first)==m.end()) {
                m[q[i].first] = ind++;
            }
            if(m.find(q[i].second)==m.end()) {
                m[q[i].second] = ind++;
            }
        }
        DSU dsu(m.size()+1);
        for(int i = 0; i < n; i++) {
            int tmp = dsu.merge(m[q[i].first],m[q[i].second]);
            cout << tmp << endl;     
        }
    }
	return 0;
} 

