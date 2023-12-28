#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

int ans = 0;
string s;
map<char, int> m1;
map<char, int> m2;
int add(int ind) {
    m1[s[ind]]++;
    m2[s[ind]]--;

    int a = 0, b = 0;
    for (char i = 'a'; i <= 'z'; i++) {
        if (m1[i]) a++;
        if (m2[i]) b++;
    }

    return a + b;
}

signed main() {
    ll t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cin >> s;

        m1.clear(); m2.clear();
        for (int i = 0; i < n; i++) {
            m2[s[i]]++;
        }

        ans = 0;
        for (char i = 'a'; i <= 'z'; i++) {
            if (m2[i]) ans++;
        }

        for (int i = 0; i < n; i++) {
            ans = max(add(i), ans);
        }

        cout << ans << endl;
    }
 }