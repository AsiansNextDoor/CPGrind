#include <bits/stdc++.h>
using namespace std;

/*
Debug checklist
- DELETE CODE PORTIONS ONE BY ONE AND RUN
- Check bounds
- Long long
- Sample case
- Edge cases
*/

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    int t; cin >> t;
    while (t--) {
        int m, x; cin >> m >> x;
        int win = 1; cout << win << " ";
        for (int i = 2; i <= x; i++) {
            int ind = m % i; if (ind == 0) ind += i;
            if (ind <= win) win++;
            cout << win << " ";
        }
        cout << endl;
    }
}