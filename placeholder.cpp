include <bits/stdc++.h>
using namespace std;
/*
*/
int n;
string a,b;
bool solve(int i, string cur) {
    if(i == n - 1) {
        return cur == b;
    }
    bool ret = 0;
    char their_xor = (cur[i] - '0') ^ (cur[i + 1] - '0') + '0';
    char their_or = (cur[i] - '0') | (cur[i + 1] - '0') + '0';
    
    //or xor
    string tmp = cur;
    tmp[i] = their_or;
    tmp[i + 1] = their_xor;
    ret |= solve(i + 1, tmp);
    //xor or
    tmp[i] = their_xor;
    tmp[i + 1] = their_or;
    ret |= solve(i + 1, tmp);
    //no change
    ret |= solve(i + 1, cur);

    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> a >> b) {
        if(a.size() != b.size()) {
            cout << "NO" << endl;
            continue;
        }
        n = a.size();
        cout << (solve(0, a) ? "YES" : "NO") << endl;
    }
    return 0;
}   
