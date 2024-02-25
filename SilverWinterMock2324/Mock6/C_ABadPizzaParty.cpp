#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second



ll MOD = 1e9+7;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
 
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

signed main() {
    IOS;

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;

        ll ans = 0;
        ll all = 1;
        for (ll i = 2; i <= 50; i++) {
            ans += i * (n/all - n/(lcm(all, i)));
            ans %= MOD;
            all = lcm(all, i);
        }

        cout << ans << endl;
    }

    //use ll
}