#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> indices(n+1);
    for (ll i = 0; i < n; i++) {
        indices[a[i]] = i+1;
    }

    set<ll> s;

    ll ans = 0;
    for (ll i = 1; i <= n; i++) { //I is num;
        ll ind = indices[i];
        //cout << ind << endl;
        if (s.size() == 0) {
            s.insert(ind);
            ans += i * (ind * (n + 1 - ind));
        }
        else {
            auto it = s.upper_bound(ind);
            if (it == s.begin()) { //n*(n+1) / 2
                //cout << "begin: " << endl;
                ll num = *it;
                //cout <<"ans: " << i * (ind * (num - ind)) << endl;
                ans += i * (ind) * (num - ind);
            }
            else if (it == s.end()) {
                //cout << "end: " << endl;
                it--;
                ll num = *it;
                //cout <<"ans: " << i * ((ind-num) * (n + 1 - ind)) << endl;
                ans += i * ((ind-num) * (n + 1 - ind));
            }
            else {
                ll n2 = *it;
                it--;
                ll n1 = *it;
                //cout <<"ans: " << i * ((ind-n1) * (n2 - ind)) << endl;
                ans += i * ((ind-n1) * (n2 - ind));
            }
            s.insert(ind);
        }
    }

    cout << ans << endl;
}