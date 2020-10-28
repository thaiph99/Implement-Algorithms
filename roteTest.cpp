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

double median(vector<int> &a)
{
    int n = a.size();
    if (n % 2 == 0)
        return (a[n / 2] + a[n / 2] - 1) / 2;
    else
        return a[n / 2];
}

vector<int> vecSub(vector<int> x, int beg, int en)
{
    vector<int> res;
    FOR(i, beg, en)
    res.push_back(x[i]);
    return res;
}

void show(vector<int> x)
{
    cout << "size : " << x.size() << endl;
    for (auto i : x)
        cout << i << " ";
    cout << endl;
}

double getMedian(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    if (n == 1)
        return (a[0] + b[0]) / 2;
    else if (n == 2)
        return (max(a[0], b[0]) + min(a[1], b[1])) / 2;

    double m1 = median(a);
    double m2 = median(b);

    if (m1 == m2)
        return m1;
    else if (m1 < m2)
    {
        vector<int> tmp1 = vecSub(b, 0, n / 2);
        vector<int> tmp2 = vecSub(a, n / 2, n - 1);
        vector<int> tmp3 = vecSub(b, 0, n / 2 - 1);
        vector<int> tmp4 = vecSub(a, n / 2, n - 1);
        if (n & 1)
            return getMedian(tmp1, tmp2);
        else
            return getMedian(tmp3, tmp4);
    }
    else
    {
        vector<int> tmp1 = vecSub(a, 0, n / 2);
        vector<int> tmp2 = vecSub(b, n / 2, n - 1);
        vector<int> tmp3 = vecSub(a, 0, n / 2 - 1);
        vector<int> tmp4 = vecSub(b, n / 2, n - 1);
        if (n & 1)
            return getMedian(tmp1, tmp2);
        else
            return getMedian(tmp3, tmp4);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> a = {1, 12, 15, 26, 38};
    vector<int> b = {2, 13, 17, 30, 45};
    cout << getMedian(a, b) << endl;
    return 0;
}
