#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

ull MOD = 562537063038967;

signed main() {
    IOS;

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    vector<ull> pows(1e6 + 1);
    ull p = 31;
    ull ppow = 1;
    for (int i = 0; i <= 1e6; i++) {
        pows[i] = ppow;
        ppow = (ppow * p) % MOD;
    }

    map<char, ull> abc;
    for (char i = 'a'; i != '{'; i++) {
        abc[i] = rng();
    }

    int n; cin >> n;
    vector<string> strings(n);
    for (int i = 0; i < n; i++) cin >> strings[i];

    multiset<ull> psums;
    psums.insert((ull)0);
    
    for (int i = 0; i < n; i++) {
        ull s = 0;
        for (int j = 0; j < strings[i].size(); j++) {
            s += abc[strings[i][j]] * pows[j];
            s %= MOD;
            psums.insert(s);
        }
    }

    for (int i = 0; i < n; i++) {
        ull s = 0;

        int sn = strings[i].size();

        vector<ull> psum(sn + 1, (ull)0);
        for (int j = 0; j < sn; j++) {
            s += abc[strings[i][j]] * pows[j];
            s %= MOD;
            psums.erase(psums.find(s));
            psum[j + 1] = s;
        }

        int l = 0;
        int r = sn, mid;
        int ans = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (psums.find(psum[mid]) != psums.end()) {
                ans = max(ans, mid);
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        s = 0;
        for (int j = 0; j < sn; j++) {
            s += abc[strings[i][j]] * pows[j];
            s %= MOD;
            psums.insert(s);
        }

        cout << ans << endl;
    }
}
