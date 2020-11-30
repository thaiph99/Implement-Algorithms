// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int gcd(int a, int b, int &x, int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int xt, yt;
    int d = gcd(b, a%b, xt, yt);
    x = yt;
    y = xt-yt*(a/b);
    return d;
}

bool sol(int a, int b, int c, int &x, int &y, int &g)
{
    g = gcd(abs(a), abs(b), x, y);
    if(c%g)
        return false;
    x*=c/g;
    y*=c/g;
    if(a<0)
        x=-x;
    if(b<0)
        y=-y;
    return true;
}

/*
56 0 13 6
*/

int main()
{
    iosb;
    int a1, b1, a2, b2;
    cin>>a1>>b1>>a2>>b2;
    int a, b, c, x, y, g;
    if(b1>b2)
        a = a2, b=-a1, c=b1-b2;
    else
        a = a1, b=-a2, c=b2-b1;
    sol(a,b,c,x,y,g);
    int k = min(floor(-x*1.0/(b/g)), floor(y*1.0/(a/g)));
//    cout<<x<<":"<<y<<endl;
    x = x+k*(b/g);
    y = y-k*(a/g);
    if(a1*x+b1!=a2*y+b2)
        swap(x,y);
    cout<<x<<" "<<y<<endl;
}
