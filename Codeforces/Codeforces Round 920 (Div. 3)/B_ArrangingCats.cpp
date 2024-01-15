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
        int n; cin >> n;
        string ini, tar; cin >> ini >> tar;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            if (ini[i] == '1' && tar[i] == '0') s1++;
            else if (ini[i] == '0' && tar[i] == '1') s2++;
        }

        cout << abs(s1 - s2) + min(s1, s2) << endl;
    }
}