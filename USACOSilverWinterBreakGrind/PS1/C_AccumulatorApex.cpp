#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll x, k; cin >> x >> k;
    
    vector<queue<pair<ll,ll>>> lists(k);
    for (ll i = 0; i < k; i++) {
        ll l; cin >> l;
        ll msum = 0;
        ll sum = 0;
        for (ll j = 0; j < l; j++) {
            ll n; cin >> n;
            sum += n;
            msum = min(sum, msum);
            if (sum > 0) {
                lists[i].push({msum, sum});
                msum = 0;
                sum = 0;
            }
        }
    }
    
    priority_queue<vector<ll>> pq;
    for (ll i = 0; i < k; i++) {
        if (!lists[i].empty()) {
            auto data = lists[i].front(); lists[i].pop();
            pq.push({data.f, data.s, i});
        }
    }
    while (!pq.empty()) {
        auto data = pq.top(); pq.pop();
        ll msum = data[0], sum = data[1], i = data[2];
        if (x + msum >= 0) x += sum;
        else break;
        if (!lists[i].empty()) {
            auto data = lists[i].front(); lists[i].pop();
            pq.push({data.f, data.s, i});
        }
    }
    
    cout << x << endl;
}