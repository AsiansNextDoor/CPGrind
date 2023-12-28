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
        
        int maxn = 0, flip = 0, maxflip = 0, maxn2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > maxn2) {
                maxn2 = a[i];
                flip = 0;
            }
            else if (a[i] < maxn2) {
                maxn = maxn2;
                flip++;
            }
            maxflip = max(maxflip, flip);
        }
        
        if (maxflip != 0) cout << maxn << endl;
        else cout << 0 << endl;
    }
}