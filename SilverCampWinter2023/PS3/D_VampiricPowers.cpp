#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), psum(n+1);
        int ma = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > ma) ma = a[i];
        }

        int ans = (1 << 8) - 1;

        psum[n] = 0;
        for (int i = n-1; i >= 0; i--) {
            psum[i] = a[i] ^ psum[i+1];
        }

        sort(psum.begin(), psum.end());

        while (true) {
            if (ans <= ma) {
                cout << ma << endl;
                break;
            }
            bool found = false;
            for (int i = 0; i < n; i++) {
                int x = ans ^ psum[i];
                auto it = upper_bound(psum.begin(), psum.end(), x);
                if (it != psum.begin()) it--;
                if (*it == x) {
                    cout << ans << endl;
                    found = true;
                    break;
                }
            }
            if (found) break;
            ans--;
        }
    }
} 