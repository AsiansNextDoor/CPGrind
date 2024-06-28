#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ans = 0;    
        int most = 0;
        for (int i = 2; i <= n; i++) {
            int k = n / i;
            int tot = i * k * (k + 1) / 2;
            if (tot > most) {
                most = tot;
                ans = i;
            }
        }

        cout << ans << endl;
    }
}