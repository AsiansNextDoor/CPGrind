#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    ll n, d; cin >> n >> d;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    deque<vector<ll>> dq; // number, index

    dq.push_back({a[0], 0});

    ll val = a[0];
    for (ll i = 1; i < n; i++) {
        auto data = dq.front();

        if (data[1] + d < i) dq.pop_front();
        data = dq.front();
        val = a[i] + data[0];
        while (!dq.empty()) {
            auto data2 = dq.back();
            if (data2[0] >= val) dq.pop_back();
            else break;
        }
        dq.push_back({val, i});
    }

    cout << val << endl;
}