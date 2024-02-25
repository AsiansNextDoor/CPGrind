#include <bits/stdc++.h>
using namespace std;

bool check(int x) {
    return true;
}

signed main() {
    int l = 0;
    int r = 1e9,mid;
    int ans = 1e9;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(check(mid))
        {
            ans = min(ans,mid);
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
}