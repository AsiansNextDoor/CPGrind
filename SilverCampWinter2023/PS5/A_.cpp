#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second

int n;
ll budget;
vector<ll> psum;

bool check(int rice, int a[]) {
    ll middle = (rice-1) / 2;
    ll right = (rice)/2 + middle;
    ll minb = 3e15;
    
    for (int i = 0; i <= n - rice; i++) {
        ll b = abs((right - middle) * (a[i+middle]) - (psum[i+right+1] - psum[i+middle+1]));
        //cout << "b1: " << b << endl;
        b += abs((middle) * a[i+middle] - (psum[i+middle] - psum[i]));
        minb = min(b, minb);
        //cout << "b: " << b << endl;
    }
    //cout << "minb: " << minb << endl;
    if (minb <= budget) return true;
    return false;
}


int besthub(int ri, int maxcoor, int a[], ll b) {
    n = ri;
    budget = b;
    psum.resize(n+1);

    for (int i = 1; i <= n; i++) {
        psum[i] = a[i-1] + psum[i-1];
    }

    // for (int i = 0; i < n; i++) cout << psum[i] << " ";
    // cout << endl;
    // for (int i = 0; i < n; i++) cout << ssum[i] << " ";
    // cout << endl;
    
    ll l = 1, r = (ll)n;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        //cout << "mid: " << mid << endl;
        if (check(mid, a)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    return l;
}

// signed main() {
//     int r, l; ll b; cin >> r >> l >> b;
//     int x[r];
//     for (int i = 0; i < r; i++) cin >> x[i];
//     cout << besthub(r, l, x, b) << endl;
// }