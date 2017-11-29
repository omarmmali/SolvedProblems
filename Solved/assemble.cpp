#include <bits/stdc++.h>
using namespace std;

//TYPEDEFS
typedef long long ll;

//MACROS
#define set(a, b) memset(a, b, sizeof(a))

/*

*/
map<string, vector<pair<int,int> > > items;
bool check(int m, int money) {
    for(auto i : items) {
        sort(i.second.begin(), i.second.end());
        bool ok = 0;
        for(int j = 0; j < i.second.size(); j++) {
            if(i.second[j].second >= m) {
                if(money >= i.second[j].first) {
                    ok = 1;
                    money -= i.second[j].first;
                    break;
                }
            }
        }
        if(!ok) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        items.clear();
        int n, money;
        cin >> n >> money;
        string type, name;
        int price, quality;
        for(int i = 0; i < n; i++) {
            cin >> type >> name >> price >> quality;
            items[type].push_back(make_pair(price, quality));
        }
        int l = 0, h = 1000000000, m;
        for(int i = 0; i < 40; i++) {
            m = (l + h) / 2;
            if(check(m, money)) {
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }
        cout << h << endl;
    }
    return 0;
}
