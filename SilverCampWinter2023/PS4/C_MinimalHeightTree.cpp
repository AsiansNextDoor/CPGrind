#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int ans = 1;
        int oldnodes = 0;
        int nodes = 0;
        for (int i = 1; i < n; i++) {
            //cout << "oldnodes: " << oldnodes << endl;
            //cout << "nodes: " << nodes << endl;
            if (a[i-1] < a[i]) {
                nodes++;
            }
            else {
                if (oldnodes > 0) {
                    oldnodes--;
                    nodes++;
                }
                else {
                    ans++;
                    oldnodes = nodes - 1;
                    nodes = 1;
                }
            }
        }

        cout << ans << endl;
    }
}