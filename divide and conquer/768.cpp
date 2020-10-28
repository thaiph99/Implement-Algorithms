// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORR(i, a, b) for (ll i = a; i >= b; i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

lli n, l, r;

lli cnt(lli x)
{
    lli res = 1;
    while (1 < x)
        x /= 2, res *= 2;
    return res * 2 - 1;
}

int isOne(lli pos, lli target, lli num)
{
    cout << pos << ":" << target << ":" << num << "  ";
    if (num < 2)
        return num;
    if (pos + 1 == target * 2)
        return num % 2;
    num /= 2;
    pos /= 2;
    if (target > pos + 1)
        target -= pos + 1;
    return isOne(pos, target, num);
}

int main(int argc, char const *argv[])
{
    freopen("768.txt", "r", stdin);
    cin >> n >> l >> r;
    lli nn = cnt(n), ans = 0;
    FOR(i, l, r)
    {
        ans += isOne(nn, i, n);
        cout << "\n------" << endl;
    }
    cout << ans << endl;
    return 0;
}
