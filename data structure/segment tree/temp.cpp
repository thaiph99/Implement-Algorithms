// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORR(i, a, b) for (ll i = a; i >= b; i--)
#define oo INT_MAX
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int MAXN = 1e5;
int n, t[4 * MAXN];

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        // cout << v << ":" << a[tl] << endl;
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] + t[v * 2 + 1];
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

void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(v * 2, tl, tm, pos, new_val);
    else
        update(v * 2 + 1, tm + 1, tr, pos, new_val);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

void show(int a[], int n)
{
    FOR(i, 1, n)
    cout << setw(5) << a[i];
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    int n = sizeof(a) / sizeof(int) - 1;
    build(a, 1, 1, n);
    cout << "tong :" << sum(1, 1, n, 1, 2) << endl;
    // show(a, n);
    show(t, 4 * n + 1);
    return 0;
}