#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string in;
    cin >> in;
    set<pair<int,int> > intervals;
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(in[i] == '.') {
            pair<int,int> cur_interval = make_pair(i, -1);
            while(in[i] == '.' && i < n) {
                i++;
            }
            cur_interval.second = i - 1;
            intervals.insert(cur_interval);
            res += cur_interval.second - cur_interval.first;
        }
    }
    while(q--) {

    }
    return 0;
}