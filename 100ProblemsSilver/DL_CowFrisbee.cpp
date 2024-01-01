#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<ll> cows(n);
	for (int i = 0; i < n; i++) {
	    cin >> cows[i];
	}
	
	ll ans = 0;
	stack<ll> s;
	for (ll i = n-1; i >= 0; i--) {
		while (!s.empty() && cows[s.top()] < cows[i]) {
		    s.pop();
		}
		if (!s.empty()) {
		    ans += s.top() - i + 1;
		}
		s.push(i);
	}
	
	reverse(cows.begin(), cows.end());
	
	while (!s.empty()) {
	    s.pop();
	}
	
	for (ll i = n-1; i >= 0; i--) {
		while (!s.empty() && cows[s.top()] < cows[i]) {
		    s.pop();
		}
		if (!s.empty()) {
		    ans += s.top() - i + 1;
		}
		s.push(i);
	}
	
	cout << ans << endl;
}