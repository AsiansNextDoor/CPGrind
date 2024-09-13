#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

ll INF, MOD;

int main() {
    IOS;

    ll n, m, k; cin >> n >> m >> k;

    map<ll, vector<vector<ll>>> df;
    map<ll, vector<vector<ll>>> af;
    for (ll i = 0; i < m; i++) {
        ll d, f, t, c; cin >> d >> f >> t >> c;
        if (f) df[d].push_back({f, c});
        else af[d].push_back({t, c});
    }

    ll dstart = 2e6, aend = 0;
    vector<ll> dcosts(1e6 + 1, 0), acosts(1e6 + 1, 0);
    map<ll, ll> dmin, amin;
    set<ll> cities;
    for (ll i = 1; i <= 1e6; i++) {
        dcosts[i] = dcosts[i - 1];
        for (auto data: df[i]) {
            ll city = data[0], cost = data[1];
            if (!dmin[city]) {
                dcosts[i] += cost;
                dmin[city] = cost;
                cities.insert(city);
            }
            else if (dmin[city] > cost) {
                dcosts[i] -= dmin[city] - cost;
                dmin[city] = cost;
            }
        }
        if (cities.size() == n) dstart = min(i, dstart);
    }
    if (cities.size() != n) {
        cout << -1 << endl;
        return 0;
    }
    for (ll i = 1e6; i > 0; i--) {
        acosts[i] = acosts[i + 1];
        for (auto data: af[i]) {
            ll city = data[0], cost = data[1];
            if (!amin[city]) {
                acosts[i] += cost;
                amin[city] = cost;
                cities.erase(cities.find(city));
            }
            else if (amin[city] > cost) {
                acosts[i] -= amin[city] - cost;
                amin[city] = cost;
            }
        }
        if (!cities.size()) aend = max(i, aend);
    }

    ll ans = 1e12;
    for (ll i = dstart; i + k + 1 <= aend; i++) ans = min(dcosts[i] + acosts[i + k + 1], ans);
    
    if (ans == 1e12) cout << -1 << endl;
    else cout << ans << endl;
}