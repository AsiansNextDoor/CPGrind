#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

ull MOD = 1e9 + 7;

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

    int n, m; cin >> n >> m;

    vector<int> ans(m, 1);

    vector<string> nstrings(n), mstrings(m);
    for (int i = 0; i < n; i++) cin >> nstrings[i];
    for (int i = 0; i < m; i++) cin >> mstrings[i];

    for (int rep = 0; rep < 5; rep++) {
        vector<char> abc = {'a', 'b', 'c'};
        map<char, ull> hash;
        for (char c: abc) hash[c] = rng() % MOD;

        set<ull> memory;
        for (int i = 0; i < n; i++) {
            string s = nstrings[i];
            ull h = 0;
            for (int j = 0; j < s.size(); j++) {
                h += hash[s[j]] * pows[j];
                h %= MOD;
            }

            for (int j = 0; j < s.size(); j++) {
                for (char c: abc) {
                    if (c != s[j]) {
                        ull new_hash = ((h + (hash[c] * pows[j]) % MOD - (hash[s[j]] * pows[j]) % MOD) + MOD) % MOD;
                        memory.insert(new_hash);
                    }
                }
            }
        }

        for (int tests = 0; tests < m; tests++) {
            string q = mstrings[tests];
            ull h = 0;
            for (int i = 0; i < q.size(); i++) {
                h += hash[q[i]] * pows[i];
                h %= MOD;
            }
            if (memory.find(h) == memory.end()) ans[tests] &= 0;
        }
    }

    for (int i = 0; i < m; i++) ans[i] ? cout << "YES" << endl : cout << "NO" << endl;
}
