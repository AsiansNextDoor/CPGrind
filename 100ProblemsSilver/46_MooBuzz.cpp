#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

signed main() {
    IOS;

    int n; cin >> n;

    n--;

    int num = 1;
    while (n--) {
        num++;
        while (num % 3 == 0 || num % 5 == 0) num++;
    }

    cout << num << endl;
}