#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
#define iosb ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int nax = 1e9;

struct pt
{
    double x,y;
};

vector<pt> a, hull;

bool cw(pt a, pt b, pt c)
{
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y)<0;
}

bool ccw(pt a, pt b, pt c)
{
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y)>0;
}

double square(pt a, pt b, pt c)
{
    double s = (b.x-a.x)*(c.y-b.y)+(c.x-b.x)*(b.y-a.y);
    return fabs(s)/2.0;
}

bool cmp(const pt &a,const pt &b)
{
    return a.x<b.x || a.x==b.x && a.y<=b.y;
}

void convexHull()
{
    if(a.size()==1)
    {
        hull=a;
        return;
    }
    sort(begin(a), end(a), cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    FOR(i,1, (int)a.size()-1)
    {
        if(i==a.size()-1 || cw(p1,a[i], p2))
        {
            while(up.size() >=2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if(i==a.size()-1 || ccw(p1,a[i], p2))
        {
            while(down.size() >=2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    for(int i = 0; i < (int)up.size(); i++)
        hull.push_back(up[i]);
    for(int i = down.size() - 2; i > 0; i--)
        hull.push_back(down[i]);
}

int main()
{
    /* https://open.kattis.com/problems/convexhull */
    iosb;
    freopen("INPUT.INP", "r", stdin);
    int n;
    while(true)
    {
        cin>>n;
        if(n==0)
            return 0;
        a.clear();
        hull.clear();
        map<pair<int,int>,int> m;
        FOR(i,1,n)
        {
            pt tmp;
            cin>>tmp.x>>tmp.y;
            if(!m[ {tmp.x, tmp.y}])
                a.push_back(tmp);
            m[ {tmp.x, tmp.y}]++;
        }
        convexHull();
        reverse(begin(hull), end(hull));
        cout<<hull.size()<<endl;
        for(auto i: hull)
            cout<<i.x<<" "<<i.y<<endl;
    }
    return 0;
}
