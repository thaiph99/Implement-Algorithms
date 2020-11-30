// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int nax = 1e5+9;
int n,m, a[nax], ans;
vector<int> g[nax];

void dfs(int u, int pre, int k)
{
    cout<<u<<":"<<k<<endl;
    if(k>m)
        return;
    int ok=1;
    for(auto v : g[u])
        if(v!=pre)
        {
            ok=0;
            dfs(v, u, a[v]==1 ? k+1 : 0);
        }
    ans+=ok;
    return;
}

int main()
{
    iosb;
    int u, v;
    freopen("INPUT.INP", "r", stdin);
    cin>>n>>m;
    FOR(i,1,n)
    cin>>a[i];
    FOR(i,2,n)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,a[1]);
    cout<<ans<<endl;
}
