#include <bits/stdc++.h>
using namespace std;

//TYPEDEFS
typedef long long ll;

//MACROS
#define set(a, b) memset(a, b, sizeof(a))

/*

*/
int arr[5];
bool solve(int i, int cur)
{
    if(i == 5)
        return (cur == 23);

   return solve(i + 1, cur * arr[i]) | solve(i + 1, cur + arr[i]) | solve(i + 1, cur - arr[i]);
}
int main()
{
    while(cin >> arr[0] && arr[0] > 0)
    {
        for(int i = 1; i < 5; i++)
            cin >> arr[i];

        sort(arr, arr + 5);
        bool ok = 0;
        do
        {
            if(solve(1, arr[0]))
            {
                ok = 1;
                break;
            }
        }
        while(next_permutation(arr, arr + 5));
        cout << (ok ? "Possible" : "Impossible") << endl;
    }
    return 0;
}
