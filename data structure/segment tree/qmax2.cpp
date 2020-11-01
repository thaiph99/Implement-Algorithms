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

const int nax = 5 * 1e4;

struct tree
{
    int lazy, val;
};

vector<tree> t(4 * nax);
int n, m;

void down(int v)
{
    int tmp = t[v].lazy;
    t[2 * v].lazy += tmp;
    t[2 * v].val += tmp;
    t[2 * v + 1].lazy += tmp;
    t[2 * v + 1].val += tmp;
    t[v].lazy = 0;
}

void update(int v, int tl, int tr, int l, int r, int val)
{
    // cout << tl << ":" << tr << endl;
    if (r < tl || tr < l)
        return;
    if (l <= tl && tr <= r)
    {
        t[v].lazy += val;
        t[v].val += val;
        return;
    }
    int tm = (tr + tl) / 2;
    down(v);
    update(2 * v, tl, tm, l, r, val);
    update(2 * v + 1, tm + 1, tr, l, r, val);
    t[v].val = max(t[2 * v].val, t[2 * v + 1].val);
}

ll getSum(int v, int tl, int tr, int l, int r)
{
    if (tl > r || tr < l)
        return INT_MIN;
    if (l <= tl && tr <= r)
        return t[v].val;
    int tm = (tr + tl) / 2;
    down(v);
    return max(getSum(2 * v, tl, tm, l, r), getSum(2 * v + 1, tm + 1, tr, l, r));
}
int main(int argc, char const *argv[])
{
    iosb;
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int type, x, y, val;
    FOR(i, 1, m)
    {
        // cout << type << endl;
        cin >> type >> x >> y;
        if (type == 1)
        {
            cout << getSum(1, 1, n, x, y) << endl;
        }
        else
        {
            cin >> val;
            update(1, 1, n, x, y, val);
        }
    }
    return 0;
}
