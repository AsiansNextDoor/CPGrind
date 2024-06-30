#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

string ans = "";
int tot = 0;
void solve(string a, string b, int d) {
    tot++;
    if (d == 1) {
        ans += a + "->" + b + "\n";
        return;
    }
    string c;
    if (a == "1") {
        if (b == "2") c = "3";
        else c = "2";
    }
    else if (a == "2") {
        if (b == "1") c = "3";
        else c = "1";
    }
    else {
        if (b == "2") c = "1";
        else c = "2";
    }
    solve(a, c, d - 1);
    ans += a + "->" + b + "\n";
    solve(c, b, d - 1);
}

signed main() {
    IOS;
    
    int n; cin >> n;

    solve("1", "3", n);

    cout << ans;
    cout << "tot=" << tot << endl;
}