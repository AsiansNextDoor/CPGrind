#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second

int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> psum(n+1, 0);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        psum[i+1] = a[i] + psum[i];
    }
    
    ll sum = psum[n];
    
    if (n < 3 || sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    if (sum == 0) {
        ll n1 = 0;
        for (ll i = 1; i <= n; i++) {
            if (psum[i] == 0) n1++;
        }
        // cout << n1 << endl;
        n1 -= 2;
        
        cout << (ll)(n1*(n1+1)/2) << endl;
        return 0;
    }
    
    sum /= 3;
    ll n1 = 0, ans = 0;
    
    for (ll i = 1; i <= n; i++) {
        if (psum[i] == sum) n1++;
        if (psum[i] == sum*2) ans += n1;
    }
    cout << ans << endl;
}