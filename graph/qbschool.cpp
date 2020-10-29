// by thaiph99
#include <bits/stdc++.h>
using namespace std;
// by thaiph99
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
#define pus push_back
#define pop pop_back
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

/* ---------------------------------------------------------------------------- */

const int nax = 5 * 1e4 + 9;
vector<pii> gra[nax];
set<pii> S;
int visit[nax], n, m, k, u, v, duv;
pii kc[nax];

void dijikstra1(int u)
{
    FOR(i, 1, n)
    kc[i].first = INT_MAX;
    kc[u] = {0, 1};
    S.insert({kc[u].first, u});
    while (!S.empty())
    {
        pii t = *begin(S);
        S.erase(t);
        int u = t.se;
        for (auto i : S)
        {
            ll v = i.fi, dv = i.se;
            if (!visit[v])
            {
                visit[v] = 1;
                kc[v] = kc[u] + dv;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    iosb;
    cin >> n >> m;
    FOR(i, 1, m)
    {
        cin >> k >> u >> v >> duv;
        gra[u].pus({duv, v});
        if (k == 2)
            gra[v].pus({duv, u});
    }
    return 0;
}
