#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

signed main() {
    int n, m, c; cin >> n >> m >> c;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> psum(m+1, 0);

    for (int i = 0; i < m; i++) psum[i+1] += b[i] + psum[i];

    for (int i = 0; i < n; i++) {
        a[i] += psum[min(i+1, m)];
    }
    for (int i = 0; i < n; i++) {
        a[n-(i+1)] -= psum[max(0, m-(i+1))];
    }

    for (int i = 0; i < n; i++) cout << a[i] % c << " ";
    cout << endl;
}