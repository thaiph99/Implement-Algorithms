// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= (int)(b); i++)
#define FORR(i, a, b) for (int i = a; i >= (int)(b); i--)
#define iosb  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<ll,ll>
const ll nax=1e5+9;
int n, m, k;
vector<ii> g1[nax], g2[nax], g3[nax];
vector<ll> d1, d2, d3;

void dik(int s, vector<ll> &d, vector<ii> g[])
{
    d.assign(n+10, INT_MAX);
    d[s]=0;
    priority_queue<ii, vector<ii>, greater<ii>> que;
    que.push({0,s});
    while(!que.empty())
    {
        ii t = que.top();
        int v = t.second;
        int dv = t.first;
        que.pop();
        if(dv!=d[v])
            continue;
        for(auto e:g[v])
        {
            int to = e.first;
            int dto = e.second;
            if(d[v]+dto<d[to])
            {
                d[to]=d[v]+dto;
                que.push({d[to],to});
            }
        }
    }
}

int main()
{
    iosb;
//    freopen("INPUT.INP","r",stdin);
    int u, v, bo, xe;
    cin>>n>>m>>k;
    FOR(i,1,m)
    {
        cin>>u>>v>>bo>>xe;
        g1[u].push_back({v, xe});
        g2[v].push_back({u, bo});
        g3[v].push_back({u, xe});
    }
    dik(1,d1, g1);
    dik(k,d2, g2);
    dik(n,d3, g3);
    ll ans=INT_MAX;
    FOR(i,1,n)
    if(d1[i]+d2[i]<=59)
        ans=min(ans, d1[i]+d3[i]);
    cout<<ans<<endl;
}
