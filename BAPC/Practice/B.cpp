#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    ll n; cin >> n;
    ll ans = 1;
    while (n % 57 == 0) {
        n /= 57;
        ans++;
    }

    cout << ans << endl;
}