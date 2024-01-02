#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second
ll n, m, k, s;
ll amax, bmax; //index of ta, tb (up to)
vector<pair<ll,ll>> ta, tb;
vector<pair<ll,ll>> daya, dayb;

auto comp = [](const pair<ll, ll>& lhs, const pair<ll, ll>& rhs) {
    return lhs.first < rhs.first;
};

bool check(ll x) {
    ll mina = daya[x].f;
    ll minb = dayb[x].f;

    ll maxg = 0;
    for (ll a = 0; a < ta.size(); a++) {
        ll cur = ta[a].f;
        if (cur * mina > s) break;
        auto it = upper_bound(tb.begin(), tb.end(), make_pair((s - (cur * mina)) / minb, 0), comp);
        ll sum = 0;
        if (it == tb.begin()) {
            //cout << "first" << endl;
            sum = a+1;
        }
        else {
            //cout << "second" << endl;
            it--;
            auto data = *it;
            //cout << data.f << " " << data.s << endl;
            sum = a+1 + (it - tb.begin()) + 1;
        }

        if (sum > maxg) {
            //cout << "maxg: " << maxg << "  sum: " << sum << endl;
            maxg = sum;
            amax = a;
            bmax = sum - (a + 1) - 1; // -1 means tb is not used
        }
    }

    
    for (ll b = 0; b < tb.size(); b++) {
        ll cur = tb[b].f;
        if (cur*minb > s) break;
        auto it = upper_bound(ta.begin(), ta.end(), make_pair((s - (cur * minb)) / mina, 0), comp);
        ll sum = 0;
        if (it == ta.begin()) {
            //cout << "third" << endl;
            sum = b+1;
        }
        else {
            //cout << "fourth" << endl;
            it--;
            sum = b+1 + (it - ta.begin()) + 1;
        }

        if (sum > maxg) {
            //cout << "maxg: " << maxg << "  sum: " << sum << endl;
            maxg = sum;
            amax = sum - (b + 1) - 1; // -1 means ta is not used
            bmax = b;
        }
    }

    if (maxg >= k) return true;
    return false;
}

signed main() {
    cin >> n >> m >> k >> s;

    daya.resize(n), dayb.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> daya[i].f;
        daya[i].s = i+1;
        if (i != 0 && daya[i].f >= daya[i-1].f) {
            daya[i].f = daya[i-1].f;
            daya[i].s = daya[i-1].s;
        }
    }
    for (ll i = 0; i < n; i++) {
        cin >> dayb[i].f;
        dayb[i].s = i+1;
        if (i != 0 && dayb[i].f >= dayb[i-1].f){
            dayb[i].f = dayb[i-1].f;
            dayb[i].s = dayb[i-1].s;
        }
    }

    ll t, c;
    for (ll i = 0; i < m; i++) {
        cin >> t >> c;
        if (t == 1) {
            ta.push_back({c, i+1});
        }
        else {
            tb.push_back({c, i+1});
        }
    }
    sort(ta.begin(), ta.end());
    sort(tb.begin(), tb.end());

    for (ll i = 1; i < ta.size(); i++) ta[i].f += ta[i-1].f;
    for (ll i = 1; i < tb.size(); i++) tb[i].f += tb[i-1].f;

    //for (ll i = 0; i < ta.size(); i++) cout << ta[i].f << " ";
    //cout << endl;
    //for (ll i = 0; i < tb.size(); i++) cout << tb[i].f << " ";
    //cout << '\n';

    ll l = 0, r = n-1, ans = -1, ansa, ansb;
    while (l < r) {
        ll mid = (l + r) / 2;
        //cout << "mid: " << mid << endl;
        if (check(mid)) {
            ans = mid;
            r = mid;
            ansa = amax;
            ansb = bmax;
            //cout << ansa << " and " << ansb << endl;
        }
        else {
            l = mid + 1;
        }
    }

    if (ans == -1) cout << -1 << endl;
    else {
        cout << ans+1 << endl;  
        while (k--) {
            if (ansa >= 0) {
                cout << ta[ansa].s << " " << daya[ans].s << endl;
                ansa--;
            }
            else {
                cout << tb[ansb].s << " " << dayb[ans].s << endl;
                ansb--;
            }
        }
    }
}