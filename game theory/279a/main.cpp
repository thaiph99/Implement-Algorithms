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

const int nax=1e3;

int main(int argc, char const *argv[])
{
    iosb;
    int x,y,t;
    cin>>x>>y;
    if((x==0 && y==0) || (x==1 && y==0))
        t=0;
    else if(x+y-1>0 && y-x<=0)
        t=(x-1)*4+1;
    else if(y-x>0 && y+x>=0)
        t=(y-1)*4+2;
    else if(y+x<0 && y-x>=0)
        t=(-x-1)*4+3;
    else
        t=-y*4;
    cout<<t<<endl;
    return 0;
}
