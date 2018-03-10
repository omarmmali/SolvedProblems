#include <bits/stdc++.h>
using namespace std;
bool isValid(int i,int j) {
    return (i >= 0 && j >= 0 && i < 8 && j < 8);
}
int bfs(pair<int,int> s, pair<int,int> e) {
    int vis[8][8] = {0};
    queue<pair<int,int> > q;
    q.push(s);
    int delta_i[] = {-2,-2,2,2,-1,-1,1,1}, delta_j[] = {-1,1,-1,1,-2,2,-2,2};
    while(q.size()) {
        pair<int,int> cur = q.front();
        q.pop();
        if(cur == e) {
            return vis[cur.first][cur.second];
        }
        for(int k = 0; k < 8; k++) {
            int next_i = cur.first  + delta_i[k], next_j = cur.second + delta_j[k];
            if(isValid(next_i,next_j) && !vis[next_i][next_j]) {
                q.push(make_pair(next_i,next_j));
                vis[next_i][next_j] = 1 + vis[cur.first][cur.second];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    while(cin >> a >> b) {
        pair<int,int> s = make_pair(a[1]-'1',a[0]-'a');
        pair<int,int> e = make_pair(b[1]-'1',b[0]-'a');
        printf("To get from %s to %s takes %d knight moves.\n",a.c_str(),b.c_str(),bfs(s,e));
    }
    return 0;
}