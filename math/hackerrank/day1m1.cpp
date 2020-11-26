// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll t, x, y, n;

ll sol(ll x, ll y)
{
    if(y==1)
        return x;
    ll ans = sol(x, y/2);
    ans = ((ans%n)*(ans%n))%n;
    if(y&1)
        return ans*x%n;
    else
        return ans;
}

int main()
{
    while(true)
    {
        cin>>t;
        if(t==0)
            break;
        while(t--)
        {
            cin>>x>>y>>n;
            cout<<sol(x,y)<<endl;
        }
    }
    return 0;
}
