// #pragma GCC optimize ("trapv")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"

int INF, MOD;

signed main()
{
    IOS;

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<string> calico = {"o", "co", "ico", "lico", "alico", "calico"};
        for (int i = 0; i < 6; i++)
        {
            if (s.size() <= i)
                break;
            if (s.substr(0, i + 1) == calico[i])
            {
                s = "CALICO" + s.substr(i + 1, s.size() - (i + 1));
                break;
            }
        }

        cout << s << endl;
    }
}