#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

vector<int> add(vector<int> v1, vector<int> v2) {
    for (int i = 0; i < 64; i++) v1[i] = (v1[i] + v2[i]) % 3;
    return v1;
}

signed main() {
    IOS;

    int n, q; cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> prime(1e6 + 1, -1);
    for (int i = 2; i <= 1e6; i++) {
        if (prime[i] == -1) {
            for (int j = i; j <= 1e6; j += i) {
                if (prime[j] == -1) prime[j] = i;
            }
        }
    }

    map<int, vector<int>> hash;

    for (int i = 2; i <= 1e6; i++) {
        if (i == prime[i]) {
            vector<int> num(64);
            for (int i = 0; i < 64; i++) num[i] = rand() % 3;
            hash[i] = num;
        }
    }

    vector<vector<int>> p(n + 1, vector<int>(64, 0));
    for (int i = 1; i <= n; i++) {
        vector<int> psum = p[i - 1];

        int sieve = a[i];
        while (sieve != 1) {
            psum = add(psum, hash[prime[sieve]]);
            sieve /= prime[sieve];
        }

        p[i] = psum;
    }

    while (q--) {
        int l, r; cin >> l >> r;
        if (p[l - 1] == p[r]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}