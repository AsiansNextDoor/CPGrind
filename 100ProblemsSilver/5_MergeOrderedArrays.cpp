#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    queue<int> n;
    queue<int> m;

    int a; cin >> a;
    while (a != -1) {
        n.push(a);
        cin >> a;
    }
    int b; cin >> b;
    while (b != -1) {
        m.push(b);
        cin >> b;
    }

    n.push(-1);
    m.push(-1);

    a = n.front(); n.pop();
    b = m.front(); m.pop();
    while (a != -1 && b != -1) {
        if (a > b) {
            cout << a << " ";
            a = n.front(); n.pop();
        }
        else {
            cout << b << " ";
            b = m.front(); m.pop();
        }
    }

    if (a == -1) {
        while (b != -1) {
            cout << b << " ";
            b = m.front(); m.pop();
        }
    }
    else {
        while (a != -1) {
            cout << a << " ";
            a = n.front(); n.pop();
        }
    }
}