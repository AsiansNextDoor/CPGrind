#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    IOS;
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<ll>> cows(n);
    for (ll i = 0; i < n; i++) {
        ll w, a; cin >> w >> a;
        cows.push_back({w, a});
    }

    sort(cows.rbegin(), cows.rend());

    ll ans = 0;
    priority_queue<vector<ll>> pq;
    pq.push({(ll)2e9, m});
    for (ll i = 0; i < n; i++) {
        ll w = cows[i][0], a = cows[i][1];
        
        while (a > 0) {
            auto data = pq.top();
            ll w1 = data[0], a1 = data[1];
            if (w + k <= w1) {
                pq.pop();
                if (a < a1) {
                    pq.push({w, a});
                    pq.push({w1, a1-a});
                }
                else {
                    pq.push({w, a1});
                }
                ans += min(a, a1);
                a -= a1;
            }
            else {
                break;
            }
        }
    }

    cout << ans << endl;
}