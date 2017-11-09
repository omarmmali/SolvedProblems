#include <bits/stdc++.h>
using namespace std;
int main() {
    int l,r,h;
    int arr[10001] = {0};
    int f = -1;
    int lst = -1;
    while(cin >> l >> h >> r) {
        if(f == -1) {
            f = l;
        }
        for(int i = l; i < r; i++) {
            arr[i] = max(arr[i],h);
        }
        lst = max(lst,r);
    }
    int c = arr[f];
    vector<int> out;
    out.push_back(f);
    for(int i = f + 1; i <= lst + 1; i++) {
        if(arr[i]!=c) {
            out.push_back(c);
            out.push_back(i);
            c = arr[i];
        }
    }
    out.push_back(0);
    for(int i = 0; i < out.size(); i++) {
        if(i) {
            cout << ' ';
        }
        cout << out[i];
    }
    cout << endl;
    return 0;
}