#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

signed main() {
    IOS;

    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector<int> psum(n), ssum(n);

    int strokes = 0;
    stack<char> paint;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        while (!paint.empty() && paint.top() > c) paint.pop();
        if (paint.empty()) {
            paint.push(c);
            strokes++;
        }
        else {
            if (paint.top() < c) {
                paint.push(c);
                strokes++;
            }
        }
        psum[i] = strokes;
    }

    strokes = 0;
    paint = stack<char>();
    for (int i = n - 1; i >= 0; i--) {
        char c = s[i];
        while (!paint.empty() && paint.top() > c) paint.pop();
        if (paint.empty()) {
            paint.push(c);
            strokes++;
        }
        else {
            if (paint.top() < c) {
                paint.push(c);
                strokes++;
            }
        }
        ssum[i] = strokes;
    }

    while (q--) {
        int a, b; cin >> a >> b; a -= 2;

        int ans = 0;
        if (a >= 0) ans += psum[a];
        if (b < n) ans += ssum[b];

        cout << ans << endl;
    }
}