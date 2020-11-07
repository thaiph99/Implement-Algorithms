// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORR(i, a, b) for (ll i = a; i >= b; i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int nax = 1e5 + 3;
int t[4 * nax], a[nax];

void build(int v, int tl, int tr, int cnt)
{
    // cout << tl << ":" << tr << endl;
    if (tl == tr)
    {
        // cout << v << ":" << a[tl] << endl;
        cin >> t[v];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm, cnt - 1);
    build(2 * v + 1, tm + 1, tr, cnt - 1);
    // cout << "cnt : " << cnt << endl;
    if (cnt % 2)
        t[v] = t[2 * v] | t[2 * v + 1];
    else
        t[v] = t[2 * v] ^ t[2 * v + 1];
}

void update(int v, int tl, int tr, int pos, int val, int cnt)
{
    if (tl > tr)
        return;
    if (tl == tr)
    {
        t[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(2 * v, tl, tm, pos, val, cnt - 1);
    else
        update(2 * v + 1, tm + 1, tr, pos, val, cnt - 1);
    if (cnt % 2)
        t[v] = t[2 * v] | t[2 * v + 1];
    else
        t[v] = t[2 * v] ^ t[2 * v + 1];
}

void show(int a[], int n)
{
    FOR(i, 1, n)
    cout << a[i] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    iosb;
    freopen("INPUT.INP", "r", stdin);
    int n, q, pos, val;
    cin >> n >> q;
    build(1, 1, 1 << n, n);
    FOR(i, 1, q)
    {
        cin >> pos >> val;
        update(1, 1, 1 << n, pos, val, n);
        cout << t[1] << endl;
    }
    return 0;
}
