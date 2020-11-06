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

const int nax = 1e3;
int a[nax], m[nax];

int main(int argc, char const *argv[])
{
    iosb;
    freopen("INPUT.INP", "r", stdin);
    int n, x, cnt = 0;
    a[4] = 1, a[8] = 2, a[15] = 3, a[16] = 4, a[23] = 5, a[42] = 6;
    m[0] = INT_MAX;
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> x;
        m[a[x]]++;
        if (m[a[x]] > m[a[x] - 1])
            m[a[x]]--;
    }
    cout << n - m[a[42]] * 6 << endl;
    return 0;
}
