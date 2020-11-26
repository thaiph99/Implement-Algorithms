// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int nax = 1e2+9;
int t, n, a[nax];

int main()
{
    iosb;
    cin>>t;
    while(t--)
    {
        int xorS=0;
        cin>>n;
        FOR(i,1,n)
        {
            cin>>a[i];
            if(a[i]%2)
                xorS^=(i-1);
        }
        if(xorS)
            cout<<"First"<<endl;
        else
            cout<<"Second"<<endl;
    }
}
