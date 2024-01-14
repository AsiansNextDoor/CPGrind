#include <bits/stdc++.h>
using namespace std;

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
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        if (a[0] != 1) {
            cout << "NO" << endl;
            continue;
        }
        ll sum = 1;
        bool valid = true;
        for (int i = 1; i < n; i++) {
            if (sum < a[i]) {
                cout << "NO" << endl;
                valid = false;
                break;
            }
            sum += a[i];
        }

        if (valid) cout << "YES" << endl;
    }
}