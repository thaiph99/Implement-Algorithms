// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORR(i, a, b) for (ll i = a; i >= b; i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

/* LÃ¡t gáº¡ch hÃ¬nh L vÃ o sÃ¢n kÃ­ch thÆ°á»›c NxN (N cÃ³ dáº¡ng 2^k)

cÃ³ 1 viÃªn gáº¡ch Ä‘áº·t bÃ¬nh hoa.

LÃ¡t khÃ´ng Ä‘Æ°á»£c lÃ m vá»¡ gáº¡ch, hehe.

Thuáº­t toÃ¡n:

- Chia sÃ¢n lÃ m 4 gÃ³c.

- LÃ¡t 1 viÃªn vÃ o tÃ¢m, quay gÃ³c chá»¯ L vÃ o gÃ³c chá»©a bá»“n hoa

- Gá»i Ä‘á»‡ quy lÃ¡t 4 hÃ¬nh vuÃ´ng kÃ­ch thÆ°á»›c n/2 vá»›i cÃ¡c bÃ¬nh hoa tÆ°Æ¡ng á»©ng

lÃ  bÃ¬nh hoa ban Ä‘áº§u, vÃ  3 bÃ¬nh hoa á»Ÿ tÃ¢m (viÃªn gáº¡ch vá»«a lÃ¡t)

*/

const int nmax = 64;
#define fin "data.inp"
#define fou "data.out"
int a[nmax][nmax];
int n, k, x, y;
void nhap()
{
    //freopen(fin, "r",stdin);
    cin >> n;      //Kich thuoc san
    cin >> x >> y; //toa do bon hoa
}
void xuat()
{
    //freopen(fou,"w",stdout);//muon in ra man hinh --> thay fou="con" hoac khoa dong lenh nay
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}
int goc(int d, int c, int kt, int x, int y)
{
    int g = kt / 2;
    //Quy Æ°á»›c gÃ³c pháº§n tÆ° theo thá»© tá»± sau:

    // 1 2

    // 4 3
    if (x >= d && x < d + g)
        if (y < c + g)
            return 1;
        else
            return 2;
    else if (y < c + g)
        return 4;
    else
        return 3;
}
void chuanbi()
{
    k = 0;
    a[x][y] = -1;
}
void lat2(int d, int c, int x, int y)
{
    int vt = goc(d, c, 2, x, y);
    //cout<<vt<<endl;
    switch (vt)
    {
    case 1: //bÃ¬nh hoa á»Ÿ gÃ³c sá»‘ 1
    {
        a[d][c + 1] = k;
        a[d + 1][c + 1] = k;
        a[d + 1][c] = k;
        break;
    }
    case 2: //bÃ¬nh hoa á»Ÿ gÃ³c sá»‘ 2
    {
        a[d][c] = k;
        a[d + 1][c + 1] = k;
        a[d + 1][c] = k;
        break;
    }
    case 3: //bÃ¬nh hoa á»Ÿ gÃ³c sá»‘ 3
    {
        a[d][c] = k;
        a[d][c + 1] = k;
        a[d + 1][c] = k;
        break;
    }
    case 4: //bÃ¬nh hoa á»Ÿ gÃ³c sá»‘ 4
    {
        a[d][c] = k;
        a[d][c + 1] = k;
        a[d + 1][c + 1] = k;
        break;
    }
    }
}
void lat_san(int d, int c, int kt, int x, int y)
{
    int g, vt;
    k++;
    if (kt == 2)
        lat2(d, c, x, y);
    else
    {
        vt = goc(d, c, kt, x, y);
        g = kt / 2;
        switch (vt)
        {
        case 1: //bÃ¬nh hoa á»Ÿ gÃ³c sá»‘
        {
            a[d + g - 1][c + g] = k;

            a[d + g][c + g] = k;

            a[d + g][c + g - 1] = k;

            lat_san(d, c, g, x, y);

            lat_san(d, c + g, g, d + g - 1, c + g);

            lat_san(d + g, c + g, g, d + g, c + g);

            lat_san(d + g, c, g, d + g, c + g - 1);

            break;
        }
        case 2: //bÃ¬nh hoa á»Ÿ gÃ³c sá»‘ 2

        {
            a[d + g - 1][c + g - 1] = k;

            a[d + g][c + g] = k;

            a[d + g][c + g - 1] = k;

            lat_san(d, c, g, d + g - 1, c + g - 1);

            lat_san(d, c + g, g, x, y);

            lat_san(d + g, c + g, g, d + g, c + g);

            lat_san(d + g, c, g, d + g, c + g - 1);

            break;
        }
        case 3: //bÃ¬nh hoa á»Ÿ gÃ³c sá»‘ 3
        {
            a[d + g - 1][c + g - 1] = k;

            a[d + g - 1][c + g] = k;

            a[d + g][c + g - 1] = k;

            lat_san(d, c, g, d + g - 1, c + g - 1);

            lat_san(d, c + g, g, d + g - 1, c + g);

            lat_san(d + g, c + g, g, x, y);

            lat_san(d + g, c, g, d + g, c + g - 1);
            break;
        }
        case 4: //bÃ¬nh hoa á»Ÿ gÃ³c sá»‘ 4
        {
            a[d + g - 1][c + g - 1] = k;

            a[d + g - 1][c + g] = k;

            a[d + g][c + g] = k;

            lat_san(d, c, g, d + g - 1, c + g - 1);

            lat_san(d, c + g, g, d + g - 1, c + g);

            lat_san(d + g, c + g, g, d + g, c + g);

            lat_san(d + g, c, g, x, y);
        }
        }
    }
}
int main()
{
    nhap();
    chuanbi();
    //    xuat();
    lat_san(1, 1, n, x, y);
    xuat();
    return 0;
}