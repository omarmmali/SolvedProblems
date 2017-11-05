#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> rnk,par;
    int forests;
    
    DSU(int n) {
        forests = n;
        rnk.resize(n);
        par.resize(n);
        for(int i = 0; i < n; i++) {
            rnk[i] = 1;
            par[i] = i;
        }
    }
    
    int getPar(int x) {
        return (par[x] == x ? x : par[x] = getPar(par[x]));
    }
    
    bool merge(int x, int y) {
        x = getPar(x);
        y = getPar(y);
        if(x == y) {
            return false;
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
    freopen("output.txt", "w", stdout);
    cin >> t;
    while(t--) {
        int s, p;
        cin >> s >> p;
        pair<double,double> arr[p];
        for(int i = 0; i < p; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        vector<pair<double, pair<int,int> > > edges, mst;
        for(int i = 0; i < p; i++) {
            for(int j = i + 1; j < p; j++) {
                double cost = (arr[i].first-arr[j].first)*(arr[i].first-arr[j].first) + (arr[i].second-arr[j].second)*(arr[i].second-arr[j].second);
                edges.push_back(make_pair(cost, make_pair(i,j)));
            }
        }
        sort(edges.begin(), edges.end());
        DSU dsu(p);
        double ans;
        int cnt = 0;
        for(int i = 0; dsu.forests > s; i++) {
            if(dsu.merge(edges[i].second.first, edges[i].second.second)) {
                mst.push_back(edges[i]);
            }
        }
        cout << fixed << setprecision(2) << sqrt(mst[mst.size()-1].first) << endl;
    }
	return 0;
} 

