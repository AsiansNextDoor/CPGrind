#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
 
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> a(n), b(n), c(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i].f;
            a[i].s = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].f;
            b[i].s = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i].f;
            c[i].s = i;
        }
        
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        sort(c.rbegin(), c.rend());
        
        int friends = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (a[i].s != b[j].s && a[i].s != c[k].s && b[j].s != c[k].s) {
                        friends = max(a[i].f + b[j].f + c[k].f, friends);
                    }
                }
            }
        }
        // pair<int, int> d1, d2, d3;
        
        // int ans = 0;
        // int max1 = max(max(a1.f, b1.f), c1.f);
        // pair<int,int> s1, s2; //second round
        // pair<int,int> t1, t2; //third round
        // if (max1 == a1.f) 0;
        // else if (max1 == b1.f) {
        //     d1 = a1; d2 = a2; d3 = a3;
        //     a1 = b1; a2 = b2; a3 = b3;
        //     b1 = c1; b2 = c2; b3 = c3;
        //     c1 = d1; c2 = d2; c3 = d3;
        // }
        // else if (max1 == c1.f) {
        //     d1 = a1; d2 = a2; d3 = a3;
        //     a1 = c1; a2 = c2; a3 = c3;
        //     c1 = b1; c2 = b2; c3 = b3;
        //     b1 = d1; b2 = d2; b3 = d3;
        // }
        // ans += a1.f;
        // int i1 = a1.s;
        // if (b1.s == i1) {
        //     s1 = b2;
        //     t1 = b3;
        // }
        // else {
        //     s1 = b1;
        //     t1 = b2;
        // }
        // if (c1.s == i1) {
        //     s2 = c2;
        //     t2 = c3;
        // }
        // else {
        //     s2 = c1;
        //     t2 = c2;
        // }
            
        // if (s1.s == s2.s) {
        //     if (max(s1.f, s2.f) == s1.f) {
        //         ans += s1.f + t2.f;
        //     }
        //     else {
        //         ans += s2.f + t1.f;
        //     }
        // }
        // else {
        //     ans += s1.f + s2.f;
        // }
        
        cout << friends << endl;
    }
}