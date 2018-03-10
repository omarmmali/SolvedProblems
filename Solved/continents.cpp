#include <bits/stdc++.h>
using namespace std;
char b[21][21];
bool vis[21][21];
int delta_i[] = {-1,0,0,1}, delta_j[] = {0,-1,1,0};
int n,m;
int xi,xj;
bool isValid(int i, int j) {
    return (i >= 0 && j >= 0 && i < n && j < m && b[i][j] == b[xi][xj] && !vis[i][j]);
}
int dfs(int i, int j) {
    vis[i][j] = 1;
    int res = 1;
    for(int k = 0; k < 4; k++) {
        int next_i = i + delta_i[k], next_j = (j + delta_j[k] + m) % m;
        if(isValid(next_i,next_j)) {
            res += dfs(next_i,next_j);
        }
    }
    return res;
}
int main() {
    while(cin >> n >> m) {
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> b[i][j];
            }
        }
        cin >> xi >> xj;
        dfs(xi,xj);
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(b[i][j] == b[xi][xj] && !vis[i][j]) {
                    int tmp = dfs(i,j);
                    res = max(tmp,res);
                } 
            }
        }
        cout << res << endl;
    }
    return 0;
}