#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int INF;

int lcd(int a, int b) {
    if (a == 0)
}

signed main() {
    IOS;

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> psum(n, a[0]);
    vector<int> ssum(n, a[n - 1]);

    for (int i = 2; i < n; i++) psum[i] = lcd
}