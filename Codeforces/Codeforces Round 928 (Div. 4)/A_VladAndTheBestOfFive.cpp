#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int a = 0, b = 0;
        for (int i = 0; i < 5; i++) {
            if (s[i] == 'A') a++;
            else b++;
        }
        if (a > b) cout << "A" << endl;
        else cout << "B" << endl;
    }
}