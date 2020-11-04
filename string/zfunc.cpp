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

ll n, z[100005];
string a;
string b;
void Z_function(string a, ll n, ll f[])
{
    ll l = -1, r = -1;
    f[0] = 0;
    FOR(i, 1, n - 1)
    {
        if (i > r)
        {
            l = i;
            r = i - 1;
            while (r < n - 1 && a[r + 1] == a[r - l + 1])
                r++;
            f[i] = r - l + 1;
        }
        else
        {
            if (f[i - l] < r - i + 1)
                f[i] = f[i - l];
            else
            {
                l = i;
                while (r < n - 1 && a[r + 1] == a[r - l + 1])
                    r++;
                f[i] = r - l + 1;
            }
        }
    }
}

void showZ(int n)
{
    FOR(i, 0, n - 1)
    cout << z[i] << " ";
    cout << endl;
}

int main()
{
    iosb;
    freopen("INPUT.INP", "r", stdin);
    cin >> a;
    cin >> b;
    string s = b + "$" + a;
    cout << s << endl;
    n = s.length();
    Z_function(s, n, z);
    int ans = -1;
    FOR(i, 1, n)
    {
        if (z[n - i] == i)
            ans = i;
    }
    if (ans != -1)
        cout << string(begin(a), begin(a) + a.length() - ans) << b << endl;
    else
        cout << a << b << endl;
    return 0;
}