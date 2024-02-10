#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int maxn = 1e6;

signed main() {
    IOS;

    int n, k; cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<int> mod(2*maxn+1, 0);
    for (int i = 0; i < n; i++) {
        if (h[i] <= k) continue;
        for (int j = 0; j <= maxn / h[i]+1; j++) {
            mod[h[i]*j]++;
            //if (h[i]*j == 0) cout << h[i] << " " << j << endl;
        }
        if (k == 0) mod[h[i]] -= 1;
    }

    for (int i = 0; i < n; i++) {
        if (h[i] < k) cout << 0 << " ";
        else cout << mod[h[i] - k] << " ";
    }
} 