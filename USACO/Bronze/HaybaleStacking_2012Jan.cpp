#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    
    vector<int> hay(n+2, 0);
    
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        hay[a]++;
        hay[b+1]--;
    }
    
    for (int i = 1; i <= n; i++) {
        hay[i] += hay[i-1];
    }
    
    hay.erase(hay.begin()+n+1);
    hay.erase(hay.begin());
    sort(hay.begin(), hay.end());
    
    cout << hay[(n-1)/2] << endl;
}