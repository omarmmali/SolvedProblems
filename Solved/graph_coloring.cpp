#include <bits/stdc++.h>
using namespace std;

//TYPEDEFS
typedef long long ll;

//MACROS
#define set(a, b) memset(a, b, sizeof(a))

/*

*/

vector<vector<int> > adj;
bool colors[101];
vector<int> ans, cur_ans;
void bt(int cur) {
    if(cur == adj.size()) {
        if(cur_ans.size() > ans.size()) {
            ans = cur_ans;
        }
        return;
    }
    if(cur_ans.size() + (adj.size() - cur - 1) < ans.size()) {
        return;
    }
    bool can_be_black = 1;
    for(int i = 0; i < adj[cur].size(); i++) {
        int neighbor = adj[cur][i];
        if(colors[neighbor] == 1) {
            can_be_black = 0;
            break;
        }
    }

    if(can_be_black) {
        cur_ans.push_back(cur);
        colors[cur] = 1;
        bt(cur + 1);
        colors[cur] = 0;
        cur_ans.pop_back();
    }

    bt(cur + 1);
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, u, v;
        cin >> n >> m;
        set(colors, 0);
        adj.clear();
        adj.resize(n + 1);
        cur_ans.clear();
        ans.clear();
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        bt(1);
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++) {
            if(i) {
                cout << ' ';
            }
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}

