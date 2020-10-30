
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
const ll mod = 242521242533, nax = 1e5 + 9;
int n, m, a[nax], t[4 * nax];

void show(pair<int, int> a[], int n)
{
    FOR(i, 1, n)
    cout << setw(5) << a[i].first;
    cout << endl;
}

void show(int a[], int n)
{
    FOR(i, 1, n)
    cout << setw(5) << a[i];
    cout << endl;
}

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v].first = a[tl];
        t[v].second = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
    t[v] = t[2 * v] + t[2 * v + 1];
}

void update(int v, int tl, int tr, int l, int r)
{
    // cout << tl << ":" << tr << "--" << l << ":" << r << endl;
    if (l > r)
        return;
    if (l == tl && tr == r)
    {
        t[v] = r - l + 1 - t[v];
        return;
    }
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm));
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    t[v] = t[2 * v] + t[2 * v + 1];
    return;
}

int sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main(int argc, char const *argv[])
{
    int type, l, r;
    iosb;
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    build(a, 1, 1, n);
    FOR(i, 1, m)
    {
        show(t, n * 3);
        cin >> type >> l >> r;
        if (type == 0)
            update(1, 1, n, l, r);
        else
            cout << sum(1, 1, n, l, r) << endl;
    }
    return 0;
}