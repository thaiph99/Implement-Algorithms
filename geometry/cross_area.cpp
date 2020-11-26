// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define iosb  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct pt
{
    int x,y;
};

int getRes(int x, int y)
{
    if(x>0 && y>0)
        return 1;
    if(x<0 && y>0)
        return 2;
    if(x<0 && y<0)
        return 3;
    if(x>0 && y<0)
        return 4;
    return 0;
}

vector<int> cross(vector<vector<int>> p)
{
    vector<pt> pp;
    for(auto i:p)
    {
        pt t;
        t.x = i[0], t.y = i[1];
        pp.push_back(t);
    }
    for(auto i: pp)
        pp.insert(getRes(i.x, i.y));
    vector<pt> tt;
}

int main()
{
    return 0;
}
