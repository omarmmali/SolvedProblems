#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int,int> > pti;
struct DSU {
    vector<int> par,rnk;
    int forests;
    
    DSU(int n) {
        par.resize(n+1);
        rnk.resize(n+1);
        forests = n;
        for(int i = 1; i <= n; i++) {
            par[i] = i;
            rnk[i] = 1;
        }
    }
    
    int getPar(int x) {
        if(par[x] == x) {
            return x;
        }
        return par[x] = getPar(par[x]);
    }
    
    bool merge(int x, int y) {
        x = getPar(x);
        y = getPar(y);
        if(x == y) {
            return 0;
        }
        if(rnk[x] < rnk[y]) {
            swap(x,y);
        }
        par[y] = x;
        rnk[x] += rnk[y];
        forests--;
        return true;
    }
};
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        pair<int,int> p[n];
        for(int i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
        }
        vector<pair<int, int> > out;
        DSU dsu(n);
        int m;
        cin >> m;
        int u,v;
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            dsu.merge(u,v);
        }
        vector<pti> edges;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                edges.push_back(make_pair((p[i].first-p[j].first)*(p[i].first-p[j].first) + (p[i].second-p[j].second)*(p[i].second-p[j].second),make_pair(i+1,j+1)));
            }
        }
        sort(edges.begin(), edges.end());
        for(int i = 0; i < edges.size() && dsu.forests > 1; i++) {
            if(dsu.merge(edges[i].second.first, edges[i].second.second)) {
                out.push_back(make_pair(edges[i].second.first, edges[i].second.second));
            }
        }
        if(out.size() == 0) {
            cout << "No new highways need" << endl;
        }
        else {
            for(int i = 0; i < out.size(); i++) {
                cout << out[i].first << " " << out[i].second << endl;
            }
        }
        if(t != 0) {
            cout << endl;
        }
    }
	return 0;
} 
