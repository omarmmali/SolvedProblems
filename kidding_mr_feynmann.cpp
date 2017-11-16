#include <bits/stdc++.h>
using namespace std;
int main() {
    long double n;
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        long double a;
        for(int i = 1; ; i++) {
            if(i * i * i > n) {
                a = i - 1;
                break;
            }
        }
        long double dx = (n - (a * a * a)) / (3 * a * a); 
        cout << fixed << setprecision(4) << a + dx << endl;
    }
    return 0;
}