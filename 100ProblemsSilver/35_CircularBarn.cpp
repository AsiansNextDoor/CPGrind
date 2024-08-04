#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

signed main() {
    IOS;

    int n; cin >> n;
    map<int, int> cpos;

    int ci = 0;
    for (int i = 0; i < n; i++) {
        int cows; cin >> cows;
        while (cows--) {
            cpos[ci] = i;
            ci++;
        }
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++) { // start index for 1 - n
        int cur = 0;
        for (int j = 0; j < n; j++) {
            int p = cpos[j];
            int d = i + j;
            if (p <= d) cur += pow(d - p, 2);
            else cur += pow(p + n - d, 2);
        }
        ans = min(cur, ans);
    }
    cout << ans << endl;
}