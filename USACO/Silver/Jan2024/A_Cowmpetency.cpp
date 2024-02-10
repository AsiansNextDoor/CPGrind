#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    ll t; cin >> t;
    while (t--) {
        ll n, q, c; cin >> n >> q >> c;
        vector<ll> l(n+1, 1), r(n+1, c);
        vector<ll> scores(n+1);
        for (ll i = 1; i <= n; i++) cin >> scores[i];

        vector<pair<ll,ll>> pairs(q);
        vector<ll> va(n+1, -1);
        vector<ll> vh(n+1, -1);
        for (ll i = 0; i < q; i++) {
            cin >> pairs[i].f >> pairs[i].s;
            va[pairs[i].f] = pairs[i].s;
            vh[pairs[i].s] = pairs[i].f;
        }
        sort(pairs.begin(), pairs.end());
        ll prevh = -1;
        bool valid = true;
        vector<pair<ll,ll>> newp;
        for (ll i = 0; i < q; i++) {
            ll a = pairs[i].f;
            ll h = pairs[i].s;
            if (h == prevh) continue;
            if (prevh > a+1) {
                valid = false;
                break;
            }
            prevh = h;
            newp.push_back({a, h});
        }
        pairs = newp;

        if (!valid) {
            cout << -1 << endl;
            continue;
        }

        vector<ll> pmax(n+1, 0);
        for (ll i = 1; i <= n; i++) pmax[i] = max(scores[i], pmax[i-1]);

        set<ll> l0;
        vector<ll> hs(n+1, -1);
        for (ll i = 0; i < q; i++) {
            ll a = pairs[i].f, h = pairs[i].s;
            if (scores[h] != 0) r[h-1] = min(scores[h]-1, r[a]);
            if (pmax[h] > pmax[a]) {
                hs[a] = h;
                l0.insert(a);
            }
        }

        for (ll i = n-1; i > 0; i--) {
            r[i] = min(r[i+1], r[i]);
        }

        for (ll i = n; i > 0; i--) {
            if (scores[i] == 0 && l0.size() > 0) {
                while (true) {
                    auto it = l0.lower_bound(i);
                    if (it == l0.end()) break;
                    ll h = hs[*it];
                    l[i] = max(pmax[h-1], l[i]);
                    l0.erase(it);
                }
            }
        }


        //cout << "l: ";
        //for (ll i = 1; i <= n; i++) cout << l[i] << " ";
        //cout << endl << "r: ";
        //for (ll i = 1; i <= n; i++) cout << r[i] << " ";
        //cout << endl << "pmax: ";
        //for (ll i = 1; i <= n; i++) cout << pmax[i] << " ";
        //cout << endl;
        for (ll i = 1; i <= n; i++) {
            if (scores[i] == 0) {
                if (vh[i] != -1) l[i] = max(pmax[vh[i]]+1, l[i]);
                if (l[i] > r[i]) {
                    valid = false;
                    break;
                }
                scores[i] = l[i];
            }
            pmax[i] = max(scores[i], pmax[i]);
            if (vh[i] != -1) {
                ll a = vh[i];
                if ((pmax[a] < pmax[i-1]) || (pmax[a] >= pmax[i])) {
                    //cout << "i: " << i << endl;
                    //cout << "a: " << a << endl;
                    valid = false;
                    break;
                }
            }
        }
        //cout << "pmax: ";
        //for (ll i = 1; i <= n; i++) cout << pmax[i] << " ";
        //cout << endl;
        if (!valid) cout << -1 << endl;
        else {
            for (ll i = 1; i <= n; i++) {
                if (i == 1) cout << scores[i];
                else cout << " " << scores[i];
            }
            cout << endl;
        }

        //cout << endl << "******" << endl;
    }
}