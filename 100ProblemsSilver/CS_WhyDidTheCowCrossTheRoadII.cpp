#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, b;
	cin >> n >> k >> b;
	
	vector<int> road(n+1, 0);
	
	for (int i = 0; i < b; i++) {
	    int id; cin >> id;
	    road[id] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
	    road[i] += road[i-1];
	}
	
	int ans = b;
	for (int i = 0; i <= n - k; i++) {
	    ans = min(road[i+k] - road[i], ans);
	}
	
	cout << ans << endl;
}