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
        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].s;
            a[i].f = i+1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int xi = a[i].f, yi = a[i].s;
                int xj = a[j].f, yj = a[j].s;

                if ((xi <= xj && yi >= yj) || (xi >= xj && yi <= yj)) {
                    ans++;
                } 
                else {
                    //cout << i << " " << j << endl;
                }
            }
        }

        cout << ans << endl;
    }
}