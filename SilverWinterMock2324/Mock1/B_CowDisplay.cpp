#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

signed main() {
    ll n; cin >> n;
    set<ll> sizes;
    map<ll,ll> m;
    for (ll i = 0; i < n; i++) {
        ll ai, bi; cin >> ai >> bi;
        sizes.insert(ai);
        m[ai] += bi;
    }

    vector<ll> a;
    for (auto it = sizes.begin(); it != sizes.end(); it++) {
        a.push_back(m[*it]);
        auto top = sizes.end(); top--;
        auto comp = it;
        if (comp != top) {
            ll cur = *comp;
            comp++;
            ll next = *comp;
            a.push_back(cur - next);
        }
    }

    cout << endl;
    ll maxi = 0, sum = 0;
    for (ll i = 0; i < a.size(); i++) {
        sum += a[i];
        maxi = max(sum, maxi);
        if (sum < 0) sum = 0;
    }

    cout << maxi << endl;
}