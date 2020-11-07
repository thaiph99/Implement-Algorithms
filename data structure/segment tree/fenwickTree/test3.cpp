
#include <bits/stdc++.h>

#define maxcao 1000000

using namespace std;

int f[300000], g[300000], a[50001], KQ1, KQ2;

void thietlap(int x, int y, int d)
{
    if (x == y)
    {
        f[d] = a[x];
        g[d] = a[x];
    }
    else
    {
        thietlap(x, (x + y) / 2, 2 * d);
        thietlap((x + y) / 2 + 1, y, 2 * d + 1);
        f[d] = max(f[2 * d], f[2 * d + 1]);
        g[d] = min(g[2 * d], g[2 * d + 1]);
    }
}

void tinhmax(int dau, int cuoi, int x, int y, int d)
{
    if (dau > y || cuoi < x)
        ;
    else if (dau <= x && cuoi >= y)
        KQ1 = max(KQ1, f[d]);
    else
    {
        tinhmax(dau, cuoi, x, (x + y) / 2, 2 * d);
        tinhmax(dau, cuoi, (x + y) / 2 + 1, y, 2 * d + 1);
    }
}

void tinhmin(int dau, int cuoi, int x, int y, int d)
{
    if (dau > y || cuoi < x)
        ;
    else if (dau <= x && cuoi >= y)
        KQ2 = min(KQ2, g[d]);
    else
    {
        tinhmin(dau, cuoi, x, (x + y) / 2, 2 * d);
        tinhmin(dau, cuoi, (x + y) / 2 + 1, y, 2 * d + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("INPUT.INP", "r", stdin);
    int n, m, p, x, y, u;
    cin >> n >> m;
    cout << n << ":" << m << endl;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    thietlap(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        KQ1 = 0;
        KQ2 = maxcao;
        tinhmax(x, y, 1, n, 1);
        tinhmin(x, y, 1, n, 1);
        printf("%d\n", KQ1 - KQ2);
    }
    return 0;
}