// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i >= b; i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int nax = 1029;
int n, tc, t[nax][4 * nax], a[nax][nax], x, y, val, x1, y11;

void show(int index)
{
    FOR(i, 1, n * 3)
    cout << setw(3) << t[index][i];
    cout << endl;
}

void build(int v, int tl, int tr, int indexTree)
{
    if (tl == tr)
    {
        t[indexTree][v] = a[indexTree][tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm, indexTree);
    build(2 * v + 1, tm + 1, tr, indexTree);
    t[indexTree][v] = t[indexTree][2 * v] + t[indexTree][2 * v + 1];
}

void update(int v, int tl, int tr, int pos, int val, int indexTree)
{
    if (tl == tr)
    {
        t[indexTree][v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(2 * v, tl, tm, pos, val, indexTree);
    else
        update(2 * v + 1, tm + 1, tr, pos, val, indexTree);
    t[indexTree][v] = t[indexTree][2 * v] + t[indexTree][2 * v + 1];
}

int sum(int v, int tl, int tr, int l, int r, int indexTree)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[indexTree][v];
    int tm = (tr + tl) / 2;
    return sum(2 * v, tl, tm, l, min(tm, r), indexTree) + sum(2 * v + 1, tm + 1, tr, max(tl, tm + 1), tr, indexTree);
}

void reset(int n)
{
    FOR(i, 1, n)
    FOR(j, 1, 4 * n)
    t[i][j] = 0;
}

int main(int argc, char const *argv[])
{
    iosb;
    freopen("input.txt", "r", stdin);
    cin >> tc;
    FOR(ic, 1, tc)
    {
        cin >> n;
        reset(n);
        string type;
        while (type != "END")
        {
            cin >> type;
            if (type == "SET")
            {
                cin >> x >> y >> val;
                update(1, 1, n, y + 1, val, x + 1);
            }
            else if (type == "SUM")
            {
                cin >> x >> y >> x1 >> y11;
                ll ans = 0;
                FOR(i, x + 1, x1 + 1)
                ans += sum(1, 1, n, y + 1, y11 + 1, i);
                cout << ans << endl;
            }
        }
    }
    return 0;
}

/*
2
4
SET 0 0 1
SUM 0 0 3 3
SET 2 2 12
SUM 2 2 2 2
SUM 2 2 3 3
SUM 0 0 2 2
END
4
SET 0 0 1
SUM 0 0 3 3
SET 2 2 12
SUM 2 2 2 2
SUM 2 2 3 3
SUM 0 0 2 2
END
=>
1
12
12
13
1
12
12
13
*/