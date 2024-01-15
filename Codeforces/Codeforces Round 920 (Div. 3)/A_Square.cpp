#include <bits/stdc++.h>
using namespace std;

/*
Debug checklist
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
    IOS;
    int t; cin >> t;
    while (t--) {
        int x1, y1; cin >> x1 >> y1;
        int ans = 1;
        for (int i = 0; i < 3; i++) {
            int x, y; cin >> x >> y;
            if (x == x1) ans *= abs(y - y1);
            if (y == y1) ans *= abs(x - x1);
        }
        cout << ans << endl;
    }
}