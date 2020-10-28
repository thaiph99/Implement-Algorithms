// by thaiph99
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORR(i, a, b) for (ll i = a; i >= b; i--)
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int nax = 1e3 + 9;
pair<int, int> a[nax];
int dx[nax], dy[nax], n;
double x, y;

double cal(int x1, int y1)
{
    return fabs(x - x1) + fabs(y - y1);
}

int cal(int x, int y, int x1, int y1)
{
    return fabs(x - x1) + fabs(y - y1);
}

pair<int, int> solve()
{
    pair<int, int> ans;
    int val = INT_MAX;
    FOR(i, 1, n)
    {
        int sum = 0;
        FOR(j, 1, n)
        sum += cal(a[i].first, a[i].second, a[j].first, a[j].second);
        if (sum < val)
            val = sum, ans = a[i];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> a[i].first >> a[i].second;
        dx[i] = a[i].first, dy[i] = a[i].second;
    }
    sort(dx + 1, dx + n + 1);
    sort(dy + 1, dy + n + 1);
    x = (n % 2) ? dx[n / 2 + 1] : 1.0 * (dx[n / 2 + 1] + dx[n / 2]) / 2;
    y = (n % 2) ? dy[n / 2 + 1] : 1.0 * (dy[n / 2 + 1] + dy[n / 2]) / 2;
    cout << x << ":" << y << endl;
    double val = INT_MAX;
    pair<int, int> ans;
    FOR(i, 1, n)
    {
        double tmp = cal(a[i].first, a[i].second);
        if (tmp < val)
            val = tmp, ans = a[i];
    }
    cout << "kq1 = " << ans.first << " " << ans.second << endl;

    pair<int, int> ans1 = solve();
    cout << "kq2 = " << ans1.first << " " << ans1.second << endl;
}
