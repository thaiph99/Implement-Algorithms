// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int t,n,a[4];

bool solve()
{
    int xorSum = a[1];
    FOR(i,1,3)
    xorSum^=a[i];
    xorSum^=a[3]-a[2];
    xorSum^=a[3]-a[1];
    xorSum^=a[2]-a[1];
    return xorSum;
}

int main()
{
    iosb;
    freopen("INPUT.INP", "r", stdin);
    cin>>t;
    while(t--)
    {
        cin>>a[1]>>a[2]>>a[3];
        sort(a+1,a+4);
        if(solve())
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return (0);
}
