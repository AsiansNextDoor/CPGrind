//#pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF, MOD;

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        int n, a, b, a1, a2; cin >> n;
        for (int i = 1; i < n; i += 2) {
            cout << "?" << " " << i << " " << i + 1 << endl;
            cout.flush();
            cin >> a1;
            cout << "?" << " " << i + 1 << " " << i << endl;
            cout.flush();
            cin >> a2;
            if (a1 != a2) {
                a = i;
                b = i + 1;
                break;
            }
        }
        if (n % 2 == 1) {
            cout << "?" << " " << n << " " << 1 << endl;
            cout.flush();
            cin >> a1;
            cout << "?" << " " << 1 << " " << n << endl;
            cout.flush();
            cin >> a2;
            if (a1 != a2) {
                a = 1;
                b = n;
            }
        }

        int ans;
        for (int i = 1; i <= n; i++) {
            if (i == a || i == b) continue;
            cout << "?" << " " << i << " " << a << endl;
            cout.flush();
            cin >> a1;
            cout << "?" << " " << a << " " << i << endl;
            cout.flush();
            cin >> a2;
            if (a1 == a2) ans = b;
            else ans = a;
            break;
        }
        
        cout << "!" << " " << ans << endl;
        cout.flush();
    }
}