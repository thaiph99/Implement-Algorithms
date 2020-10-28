// by thaiph99
#include <bits/stdc++.h>

using namespace std;
// by thaiph99
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int nax = 1e3 + 9;
int tc, n, k, x;

int main(int argc, char const *argv[])
{
    iosb;
    freopen("b.txt", "r", stdin);
    cin >> tc;
    while (tc--)
    {
        set<int> ss;
        cin >> n >> k;
        FOR(i, 1, n)
        {
            cin >> x;
            ss.insert(x);
        }
        int nn = ss.size();
        if (nn != 1 && k == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if ((nn == 1 && k == 1) || k >= nn)
        {
            cout << 1 << endl;
            continue;
        }
        int ans = ceil((float)(1.0 * (nn - k)) / (k - 1));
        cout << ans + 1 << endl;
    }
    return 0;
}