#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f first
#define s second

int INF;

int w, n; 
vector<string> d;
map<string, int> ind;

int bsta(string p, int k) {
    int l = 0;
    int r = w - 1, mid;
    int ans = 1e9;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if (d[mid] >= p)
        {
            r = mid-1;
            ans = min(ans, mid);
        }
        else
        {
            l = mid+1;
        }
    }

    ans += k - 1;
    if (ans >= w || d[ans].size() < p.size() || d[ans].substr(0, p.size()) != p) {
        ans = -1;
    }
    else {
        ans = ind[d[ans]];
    }
    return ans;
}

signed main() {
    IOS;

    cin >> w >> n;
    d.resize(w);
    for (int i = 0; i < w; i++) {
        cin >> d[i];
        ind[d[i]] = i + 1;
    }

    sort(d.begin(), d.end());

    
    while (n--) {
        int k; string s;
        cin >> k >> s;
        
        cout << bsta(s, k) << endl;
    }
}