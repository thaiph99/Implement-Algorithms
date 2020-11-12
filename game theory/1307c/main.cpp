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

ll n, t, o=1, e=1;

void solve(int n)
{
    FOR(i,2,500000)
    {
        if(n<1)
            return;
        while(n%i==0 && n>=1)
        {
            cout<<i<<" "<<" ";
            if(i%2==0)
                e*=i;
            else
                o*=i;
            n/=i;
        }
    }
}

string s;

int main(int argc, char const *argv[])
{
    cin>>t;
    FOR(it,1,t)
    {
        e=o=1;
        cin>>n;
        if(n==1)
        {
            cout<<"FastestFinger"<<endl;
            continue;
        }
        solve(n);
        cout<<endl;
        cout<<e<<":"<<o<<endl;
        s=(o==1 ? "FastestFinger" : "Ashishgup");
        cout<<s<<endl;
    }
    return 0;
}
