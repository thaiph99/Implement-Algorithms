// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int nax = 1e6;
int g[nax];

int calMex(set<int> s)
{
    int ans =0;
    for(auto &i:s)
        if(i!=ans)
            return ans;
        else
            ans++;
    return ans;
}

int grundy(int n)
{
    if(n==0 || n==1)
        return 0;
    if(g[n]!=-1)
        return g[n];
    set<int> s;
    if(n>=2)
        s.insert(grundy(n-2));
    if(n>=3)
        s.insert(grundy(n-3));
    if(n>=5)
        s.insert(grundy(n-5));
    return g[n] = calMex(s);
}

void reset()
{
    FOR(i,0,109)
    g[i]=-1;
}

int main(int argc, char const *argv[])
{
    iosb;
//    freopen("INPUT.INP", "r", stdin);
    int t, n, m;
    cin>>t;
    FOR(it,1,t)
    {
        cin>>n>>m;
        if(m==1 || n%2==0)
            cout<<2<<endl;
        else
            cout<<1<<endl;
    }
    return 0;
}
