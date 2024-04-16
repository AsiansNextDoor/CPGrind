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
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        int a = arr[0];
        int b = arr[0];
        for (int i = 0; i < n; i++) {
            a &= arr[i];
            b |= arr[i];
        }
        int ac = 0;
        int bc = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == a) ac++;
            if (arr[i] == b) bc++;
        }
        
        if (ac < bc) cout << "or" << endl;
        else if (bc < ac) cout << "and" << endl;
        else cout << "sad" << endl;
    }
}