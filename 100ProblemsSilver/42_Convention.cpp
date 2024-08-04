#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

int n, m, c;
vector<int> times;

bool check(int x) {
    int bus = 1;
    int cows = 1;
    int prev = times[0];
    for (int i = 1; i < n; i++) {
        if (times[i] - prev > x || cows == c) {
            bus++;
            prev = times[i];
            cows = 0;
        }
        cows++;
    }

    if (bus > m) return false;
    return true;
}

signed main() {
    IOS;

    cin >> n >> m >> c;
    times.resize(n);
    for (int i = 0; i < n; i++) cin >> times[i];

    sort(times.begin(), times.end());

    int l = 0;
    int r = 1e9, mid;
    int ans = 1e9;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid))
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << endl;
}