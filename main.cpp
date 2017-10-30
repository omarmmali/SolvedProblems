#include <bits/stdc++.h>
using namespace std;
vector<set<int> > adj;
bool check(int cur) {
	for(auto i : adj[cur]) {
		for(auto j : adj[i]) {
			//cout << "currently: "<< cur << " " << i << " " << j << endl;
			if(j != cur && adj[cur].binary_search(j) == adj[cur].end()) {
				return false;
			}	
		}
	}
	return true;
}
int main() {
	int n,m;
	cin >> n >> m;
	adj.resize(n+1);
	int u,v;
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	bool ok = 1;
	for(int i = 1; i <= n; i++) {
		ok &= check(i);	
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
} 

