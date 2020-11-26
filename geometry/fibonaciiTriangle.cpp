#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll n, x, y, cx, cy, ans;
ll f[2000006];
ll r[2000006];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y;
    f[0] = 0;
    f[1] = 1;
    for(int i=2; i<=max(x,y)+1; i++)
        f[i]=(f[i-1]+f[i-2])%MOD;
    r[1] = 1;
    for(int i = 2; i < 2000006; ++i)
        r[i] = (MOD - (MOD/i) * r[MOD%i] % MOD) % MOD;
    x-=1,y-=1;
    n = x+y;
    cx = cy = 1;
    for(int i=x+1; i<=n; i++)
        cx=(cx*i)%MOD,cx=(cx*r[i-x])%MOD;
//      cout<<cx<<endl;
    for(int i=0; i<=y; i++)
    {
        ans=(ans+f[i+1]*cx)%MOD;
//          cout<<f[i+1]<<" "<<cx<<endl;
        cx=(cx*(n-i-x))%MOD;
        cx=(cx*r[n-i])%MOD;
    }
    for(int i=y+1; i<=n; i++)
        cy=(cy*i)%MOD,cy=(cy*r[i-y])%MOD;
//      cout<<cy<<endl;
    for(int i=0; i<=x; i++)
    {
        ans=(ans+f[i+1]*cy)%MOD;
//          cout<<f[i+1]<<" "<<cy<<endl;
        cy=(cy*(n-i-y))%MOD;
        cy=(cy*r[n-i])%MOD;
    }
    cout<<ans;
    return 0;
}
