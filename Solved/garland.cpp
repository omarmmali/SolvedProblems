#include <bits/stdc++.h>
using namespace std;
int main() {
    double n, A;
    while(cin >> n >> A) {
        double cof_l2[1001] = {0};
        double cof_A[1001] = {0};
        double l[1001] = {0};
        l[1] = A;
        cof_A[1] = A;
        cof_l2[2] = 1;
        cof_A[2] = 0;
        
        double K = 0;
        for(int i = 3; i <= 1000; i++) {
            cof_l2[i] = (2 * cof_l2[i-1]) - cof_l2[i-2];
            cof_A[i] = (2 * cof_A[i-1]) - cof_A[i-2] + 2;
            if ((K * cof_l2[i]) + cof_A[i] < 0 ) {
                K = (-cof_A[i]) / cof_l2[i];
            }
            l[i] = (K * cof_l2[i]) + cof_A[i];
        }
        cout <<fixed << setprecision(2) << l[(int)n] << endl;
    }
    return 0;
} 