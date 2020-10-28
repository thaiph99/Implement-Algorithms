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
int a[nax], b[nax], n;

int main(int argc, char const *argv[])
{
    iosb;
    // freopen("input.txt", "r", stdin);
    cin >> n;
    FOR(i, 1, n)
    cin >> a[i] >> b[i];
    if (n == 1)
        return cout << 1, 0;
    int cur = a[1], ans = 0;
    FOR(i, 2, n - 1)
    {
        if (a[i] - b[i] > cur)
            ans++, cur = a[i];
        else if (a[i] + b[i] < a[i + 1])
            ans++, cur = a[i] + b[i];
        else
            cur = a[i];
    }
    return cout << ans + 2, 0;
}
