#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;
    int n; cin >> n;
    vector<vector<int>> cows(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> cows[i][0] >> cows[i][1];
    sort(cows.rbegin(), cows.rend());
    
    set<int> time;
    for (int i = 0; i < 10000; i++) time.insert(i);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int g = cows[i][0];
        int d = cows[i][1];

        auto it = time.lower_bound(d);
        if (it != time.begin()) {
            it--;
            time.erase(it);
            ans += g;
        }
    }

    cout << ans << endl;
}