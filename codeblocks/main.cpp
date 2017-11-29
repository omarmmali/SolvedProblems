#include <bits/stdc++.h>
using namespace std;

//TYPEDEFS
typedef long long ll;

//MACROS
#define set(a, b) memset(a, b, sizeof(a))

/*

*/

int main() {
    int n;
    while(cin >> n) {
        int a_x = 0;
        int e_x = 0;
        int o_x = 0;
        for(int i = 1; i <= n; i++) {
            int x = 0;
            for(int j = 1; j <= n; j++) {
                if(j > 1) {
                    cout << ' ';
                }
                cout << i % j;
                x ^= (i % j);
            }
            cout << " XOR = " << x << endl;
            a_x ^= x;
            if(i % 2 == 0) {
                e_x ^= x;
            }
            else {
                o_x ^= x;
            }
        }
        cout << "XOR ALL = " << a_x << endl;
        cout << "XOR EVEN = " << e_x << endl;
        cout << "XOR ODD = " << o_x << endl;
    }
    return 0;
}
