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

const int nax = 100000;
int t1[4 * nax], t2[4 * nax], a[nax], an1, an2;

void build(int v, int tl, int tr)
{
    // cout << v << ":" << tl << ":" << tr << endl;
    if (tl == tr)
    {
        t1[v] = a[tl];
        t2[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t1[v] = max(t1[2 * v], t1[2 * v + 1]);
    t2[v] = min(t2[2 * v], t2[2 * v + 1]);
}

void getAns(int v, int tl, int tr, int l, int r)
{
    if (r < tl || tr < l)
        return;
    else if (l <= tl && tr <= r)
    {
        an1 = max(an1, t1[v]);
        an2 = min(an2, t2[v]);
        return;
    }
    int tm = (tl + tr) / 2;
    getAns(2 * v, tl, tm, l, min(r, tm));
    getAns(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void show(int f[], int n)
{
    FOR(i, 1, n)
    cout << f[i] << " ";
    cout << "--------" << endl;
}

int main(int argc, char const *argv[])
{
    iosb;
    freopen("INPUT.INP", "r", stdin);
    int n, m, x, y;
    cin >> n >> m;
    FOR(i, 1, n)
    cin >> a[i];
    build(1, 1, n);
    FOR(i, 1, m)
    {
        an1 = INT_MIN, an2 = INT_MAX;
        cin >> x >> y;
        getAns(1, 1, n, x, y);
        cout << an1 - an2 << endl;
    }
    return 0;
}
