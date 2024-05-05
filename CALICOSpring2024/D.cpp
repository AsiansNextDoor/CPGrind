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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        
        if (n <= k) {
            cout << -1 << endl;
            continue;
        }
        
        set<int> blocks;
        for (int i = 0; i < n; i++) {
            if (s[i] == '#') blocks.insert(i+1);
        }
        
        int ans = 0;
        int pos = n+1;
        while (pos > n) {
            pos = 0;
            ans++;
            while (true) {
                int limit = pos + k+1;
                if (limit > n) {
                    pos = n+1;
                    break;
                }
                auto it = blocks.upper_bound(limit);
                if (it == blocks.begin()) break;
                it--;
                if (*it < pos) break;
                else {
                    pos = *it;
                    blocks.erase(it);
                }
            }
        }
        
        cout << ans-1 << endl;
    }
}