#include <bits/stdc++.h>
using namespace std;
 
int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n; cin >> n;
    
    vector<pair<int, int>> cows;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        
        cows.push_back({y, x});
    }
    
    sort(cows.begin(), cows.end());
    
    int i = 0, j = n-1;
    
    int minT = 0;
    while (i <= j) {
        int x = min(cows[i].second, cows[j].second);
        if (i==j) x /= 2;
        minT = max(M, cows[i].first + cows[j].first);
        cows[i].second -= x;
        cows[j].second -= x;
        if (cows[i].second == 0) i++;
        if (cows[j].second == 0) j--;
    }
    cout << minT << endl;
}