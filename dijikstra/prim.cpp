// by thaiph99
#include <bits/stdc++.h>
using namespace std;

// by thaiph99
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define pus push_back
#define pob pop_back
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

/* ---------------------------------------------------------------------------- */

const int nax = 1e4 + 9;
vector<pii> graph[nax];
int n, m, uu, vv, ww, visit[nax];
priority_queue<pii, vector<pii>, greater<pii>> mstSet;

int primAlgo()
{
    ll ans = 0;
    mstSet.push(pii(1, 0));
    while (!mstSet.empty())
    {
        while (!mstSet.empty() && visit[mstSet.top().fi])
            mstSet.pop();
        if (mstSet.empty())
            break;
        pii e = mstSet.top();
        mstSet.pop();
        visit[e.fi] = 1;
        ans += e.se;
        for (pii ee : graph[e.fi])
            mstSet.push(ee);
        // cout << e.fi << ":" << e.se << "  -------\n";
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    iosb;
    freopen("prim.txt", "r", stdin);
    cin >> n >> m;
    FOR(i, 1, m)
    {
        cin >> uu >> vv >> ww;
        graph[uu].pus(pii(vv, ww));
        graph[vv].pus(pii(uu, ww));
    }
    cout << primAlgo() << endl;
    return 0;
}
