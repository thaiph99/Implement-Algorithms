#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct pt
{
    double x, y;
};

bool cmp(pt a, pt b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(pt a, pt b, pt c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void convex_hull(vector<pt> &a)
{
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++)
    {
        if (i == a.size() - 1 || cw(p1, a[i], p2))
        {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2))
        {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

double S(double x0, double y0, double x1, double y1, double x2, double y2)
{
    double area = (double)x0 * y1 - y0 * x1 + x1 * y2 - y1 * x2 + x2 * y0 - y2 * x0;
    return abs(area / 2);
}
int main()
{
    ll t;
    cin >> t;
    for (int ttt = 1; ttt <= t; ttt++)
    {

        ll n, m;
        cin >> n >> m;
        vector<pt> a;
        for (int i = 0; i < n; i++)
        {
            pt p;
            cin >> p.x >> p.y;
            a.push_back(p);
        }
        convex_hull(a);
        /// -> cww
        reverse(a.begin(), a.end());

        ll temp = LONG_MAX, k;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i].x < temp)
            {
                temp = a[i].x;
                k = i;
            }
        }

        vector<pt> v;
        for (int i = k; i < a.size(); i++)
        {
            pt point;
            point.x = a[i].x;
            point.y = a[i].y;
            v.push_back(point);
        }
        for (int i = 0; i < k; i++)
        {
            pt point;
            point.x = a[i].x;
            point.y = a[i].y;
            v.push_back(point);
        }
        //cout<<v.size();

        cout << "Case " << ttt << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i].x << " " << v[i].y << endl;
        }
        cout << v[0].x << " " << v[0].y << endl;

        //a[n].x = a[0].x;
        //a[n].y = a[0].y;
        pt tt;
        tt.x = v[0].x;
        tt.y = v[0].y;
        v.push_back(tt);
        double area = 0;
        for (int i = 0; i < v.size() - 1; ++i)
        {
            area += v[i].x * v[i + 1].y - v[i].y * v[i + 1].x;
        }
        area = abs(area / 2);

        //cout<<area;

        for (int i = 0; i < m; i++)
        {
            double x, y, s = 0;
            cin >> x >> y;
            for (int j = 0; j < v.size() - 1; j++)
            {
                s += S(x, y, v[j].x, v[j].y, v[j + 1].x, v[j + 1].y);
            }
            s += S(x, y, v[v.size() - 1].x, v[v.size() - 1].y, v[0].x, v[0].y);
            if (!(fabs(area - s) <= 0.000001))
            {
                cout << x << " " << y << " is safe!" << endl;
            }
            else
            {
                cout << x << " " << y << " is unsafe!" << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
