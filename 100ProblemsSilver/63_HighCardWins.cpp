#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

signed main() {
    IOS;

    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    int n; cin >> n;
    set<int> bcards;
    vector<int> ecards(n);

    for (int i = 1; i <= 2 * n; i++) bcards.insert(i);
    for (int i = 0; i < n; i++) {
        cin >> ecards[i];
        bcards.erase(bcards.find(ecards[i]));
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = bcards.upper_bound(ecards[i]);
        if (it == bcards.end()) it = bcards.begin();
        else ans++;

        bcards.erase(it);
    }

    cout << ans << endl;
}