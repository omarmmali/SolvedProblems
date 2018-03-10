#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<int, pair<int, int> > > vpti;
struct DSU {
    vector<int> par, rnk;
    int forests;
    DSU(int n) {
        rnk.resize(n+1);
        par.resize(n+1);
        for(int i = 1; i <= n; i++) {
            par[i] = i;
            rnk[i] = 1;
        }
        forests = n;
    }
    int find_par(int x) {
        if(par[x] == x) {
            return x;
        }
        return par[x] = find_par(par[x]);
    }
    bool merge(int x, int y) {
        if(find_par(x) == find_par(y)) {
            return false;
        }
        x = par[x];
        y = par[y];
        if(rnk[y] > rnk[x]) {
            swap(x,y);
        }
        par[y] = x;
        rnk[x] += (rnk[x] == rnk[y]);
        forests--;
        return true;
    }
};
pair<vpti, int> MST(vpti edges, int n, pair<int, pair<int,int> > ignore) {
    DSU dsu(n);
    int cst = 0;
    vpti ret;
    for(int i = 0; i < edges.size(); i++) {
        if((edges[i] != ignore) && dsu.merge(edges[i].second.first, edges[i].second.second)) {
            ret.push_back(edges[i]);
            cst += edges[i].first;
        }
    }
    return make_pair(ret,(dsu.forests==1?cst:(1e9)));
} 
int main() {
    int t;
    freopen("output.txt","w",stdout);
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        int u, v, c;
        vpti edges(m);
        for(int i = 0; i < m; i++) {
            cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        }
        sort(edges.begin(), edges.end());
        pair<vpti, int> first_mst = MST(edges, n, make_pair(-1, make_pair(-1,-1)));
        cout << first_mst.second << " ";
        int mn = (1e9);
        for(int i = 0; i < first_mst.first.size(); i++) {
            mn = min(mn, MST(edges, n, first_mst.first[i]).second);
        }
        cout << mn << endl;
    }
	return 0;
} 

