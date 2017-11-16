include <bits/stdc++.h>
using namespace std;
vector<long long> parse(string in) {
    vector<long long> ret;
    for(int i = 0; i < in.size(); i++) {
        string tmp;
        while(in[i] != ' ' && i < in.size()) {
            tmp += in[i++];
        }
        if(tmp.size()) {
            ret.push_back(stol(tmp.c_str()));
        }
    }
    return ret;
}
long long p(long long a, long long b) {
    if(b == 0) {
        return 1;
    }
    if(b == 1) {
        return a;
    }
    long long ret = p(a, b / 2);
    ret *= ret;
    if(b % 2) {
        ret *= a;
    }
    return ret;
}
int main() {
    int x;
    while(cin >> x) {
        cin.ignore();
        string in;
        getline(cin, in);
        vector<long long> coff = parse(in);
        long long res = 0;
        int n = coff.size();
        for(int i = 0; i < n - 1; i++) {
            res += (n - 1 - i) * coff[i] * p(x, n - 2 - i); 
        }
        cout << res << endl;
    }
    return 0;
}
