#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

signed main() {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        
        while (true) {
            vector<ll> nums;
            
            ll n2 = n;
            while (n2 != 0) {
                ll dig = n2 % 10;
                if (dig != 0 && dig != 1) nums.push_back(dig);
                n2 /= 10;
            }
            bool divisible = true;
            for (ll i: nums) {
                if (n % i != 0) {
                    divisible = false;
                    break;
                }
            }
            
            if (divisible) break;
            n++;
        }
        
        cout << n << endl;
    }
 }