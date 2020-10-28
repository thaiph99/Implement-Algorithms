// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i >= b; i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

struct cus
{
    int t, l, h;
};
const int nax = 109;
cus a[nax];
int tc, n, m;

main(int argc, char const *argv[])
{
    iosb;
    freopen("input.txt", "r", stdin);
    cin >> tc;
    while (tc--)
    {
        cin >> n >> m;
        FOR(i, 1, n)
        cin >> a[i].t >> a[i].l >> a[i].h;
        int cl = m, ch = m, check = 1;
        a[0].t = 0, a[0].l = 0, a[0].h = 0;
        FOR(i, 1, n)
        {
            // cout << cl << ":" << ch << "-" << (a[i].t - a[i - 1].t) << ":" << (a[i].t - a[i - 1].t) << endl;
            cl = cl - (a[i].t - a[i - 1].t), ch = ch + (a[i].t - a[i - 1].t);
            if (cl > a[i].h || a[i].l > ch)
            {
                check = 0;
                break;
            }
            cl = max(cl, a[i].l), ch = min(ch, a[i].h);
        }
        cout << (check ? "YES" : "NO") << endl;
    }
    return 0;
}
