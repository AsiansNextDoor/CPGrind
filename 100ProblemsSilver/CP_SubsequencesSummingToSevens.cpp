#include <bits/stdc++.h>
using namespace std;

int main() {	
    int n;
	cin >> n;
	
	vector<int> photo = {0};
	for (int i = 0; i < n; i++) {
	    int id; cin >> id;
	    photo.push_back((id+photo[i]) % 7);
	}
	
	
	int ans = 0;
	for (int i = 0; i < 7; i++) {
	    int ind1 = 0, ind2 = 0;
	    for (int j = 1; j <= n; j++) {
	        if (photo[j] == i) {
	            ind1 = j;
	            break;
	        }
	    }
	    for (int j = n; j > 0; j--) {
	        if (photo[j] == i) {
	            ind2 = j;
	            break;
	        }
	    }
	    
	    ans = max(ind2-ind1, ans);
	}
	
	cout << ans << endl;
}
