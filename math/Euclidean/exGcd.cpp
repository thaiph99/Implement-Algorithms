// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int gcd1(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int xt, yt;
    int d = gcd1(b, a % b, xt, yt);
    x = yt;
    y = xt - yt * (a / b);
    return d;
}

bool sol(int a, int b, int c, int &x, int &y, int &g)
{
    g = gcd1(abs(a), abs(b), x, y);
    if (c % g != 0)
        return false;
    x *= c / g;
    y *= c / g;
    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;
    return true;
}

int main()
{
    int a, b, c, x, y, g;
    cin >> a >> b >> c;
    if (sol(a, b, c, x, y, g))
        cout << x << " " << y << endl;
    else
        cout << "no solution for this case" << endl;
}
