#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        
        for (int i = n-k-1; i >= 0; i--) cout << i+1 << " ";
        for (int i = n-k; i < n; i++) cout << i+1 << " ";
        cout << endl;
    }
}