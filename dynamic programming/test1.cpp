// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORR(i, a, b) for (ll i = a; i >= b; i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int nax = 1e5 + 9;
int n, a[nax], tc;

int main(int argc, char const *argv[])
{
    iosb;
    freopen("input.txt", "r", stdin);
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        FOR(i, 1, n)
        cin >> a[i];
        int ans1 = 0, ans2 = 0;
        int l = 0, r = 0;
        bool c1 = false, c2 = false;
        FOR(i, 1, n - 1)
        {
            // cout << "test1 " << a[i] << " " << a[i + 1] << endl;
            if (a[i] == a[i + 1])
                continue;
            if (c1 && !c2 && a[i] >= a[i + 1])
                ans1 = max(ans1, min(l, r)), r = 0;
            if (!c1 && c2 && a[i] <= a[i + 1])
                ans2 = max(ans2, min(l, r)), l = 0;
            if (a[i] < a[i + 1])
                l++, c1 = true, c2 = false;
            if (a[i] > a[i + 1])
                r++, c2 = true, c1 = false;
            // cout << "test2 " << l << ":" << r << ":" << ans1 << ":" << ans2 << endl;
        }
        if (c1 && !c2)
            ans1 = max(ans1, min(l, r));
        if (!c1 && c2)
            ans2 = max(ans2, min(l, r));
        cout << ans2 << " " << ans1 << endl;
    }
    return 0;
}
