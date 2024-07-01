#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

signed main() {
    IOS;

    int x, n; cin >> x >> n;

    multiset<int> s; s.insert(x);
    set<int> l; 
    l.insert(0);
    l.insert(x);
    while (n--) {
        int p; cin >> p;
        auto it = l.upper_bound(p);
        int s2 = *it;
        it--;
        int s1 = *it;
        int len = s2 - s1;
        s.erase(s.find(len));
        s.insert(s2-p);
        s.insert(p-s1);
        l.insert(p);
        
        auto ans = s.end();
        ans--;
        cout << *ans << " ";
    }
}