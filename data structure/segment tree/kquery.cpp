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
const ll mod = 242521242533;
const int nax = 3 * 1e4 + 1;
int n, t[4 * nax], k, a[nax], m;

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tl] > k;
        return;
    }
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l>r)
        return 0;
    if(l==tl && r==tr)
        return t[v];
    int tm = (tr+tl)/2;
    return query(2*v, tl, tm, l, min(tm, r))+query(2*v+1, tm+1, tr, max(l, tm+1), r);
}

void show(int a[], int n)
{
    FOR(i, 1, n)
    cout << setw(5) << a[i];
    cout << endl;
}

int main(int argc, char const *argv[])
{
    iosb;
    freopen("input.txt", "r", stdin);
    cin >> n;
    FOR(i, 1, n)
    cin >> a[i];
    cin >> m;
    int x, y;
    FOR(i, 1, m)
    {
        cin >> x >> y >> k;
        build(a, 1, 1, n);
        cout << query(1, 1, n, x, y) << endl;
    }
    return 0;
}
/*
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2
=>
2
0
3
*/
