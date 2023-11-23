#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    
    set<int> start;
    set<int> end;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        start.insert(a);
        end.insert(b);
    }
    
    
    int cur = 0;
    int ans = 0;
    while (!start.empty() && !end.empty()) {
        if (*start.begin() <= *end.begin()) {
            cur++;
            start.erase(start.begin());
        }
        else {
            cur--;
            end.erase(end.begin());
        }
        ans = max(cur, ans);
    }
    
    cout << ans << endl;
}