#include <bits/stdc++.h>
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
    string in;
    while(getline(cin, in)) {
        vector<long long > coff = parse(in);
        getline(cin, in);
        vector<long long> x = parse(in);
        int n = coff.size();
        for(int i = 0; i < x.size(); i++) {
            if(i) {
                cout << ' ';
            }
            long long res = 0;
            for(int j = 0; j < n; j++) {
                res += coff[j] * p(x[i], n - j - 1);
            }
            cout << res;
        }
        cout << endl;
    }
    return 0;
}