#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> fraction;
#define num first
#define denom second

fraction n;

string search(fraction cur, fraction left_par, fraction right_par) {
    if(cur == n) {
        return "";
    }
    if (cur.num * n.denom > n.num * cur.denom) {
        return "L" + search(fraction(left_par.num + cur.num, left_par.denom + cur.denom), left_par, cur);
    }
    else {
        return "R" + search(fraction(right_par.num + cur.num, right_par.denom + cur.denom), cur, right_par);
    }
}
int main() {
    while(cin >> n.num >> n.denom) {
        if((n.num == 1) && (n.denom == 1)) {
            break;
        }
        cout << search(fraction(1,1),fraction(0,1), fraction(1,0)) << endl;
    }
    return 0;
} 