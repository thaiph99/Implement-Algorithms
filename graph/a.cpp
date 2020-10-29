// by thaiph99
#include <bits/stdc++.h>

using namespace std;
// by thaiph99
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORR(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define iosb                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

const int nax = 1e5 + 9;
int tc, n, l, a[nax];

double solve()
{
    int v1 = 1, v2 = 1, head = 1, rear = n;
    double ans = 0, x1 = 0, x2 = l;
    while (head <= rear)
    {

        double tmp1 = a[head] - x1, tmp2 = x2 - a[rear];
        double t1 = tmp1 / v1, t2 = tmp2 / v2;
        if (t1 < t2)
        {
            x1 = a[head++];
            v1++;
            x2 = x2 - v2 * t1;
            ans += t1;
        }
        else if (t1 > t2)
        {
            x2 = a[rear--];
            v2++;
            x1 = x1 + v1 * t2;
            ans += t2;
        }
        else
        {
            x1 = a[head++];
            x2 = a[rear--];
            v1++, v2++;
            ans += t1;
        }
    }
    return ans + (x2 - x1) / (v1 + v2);
}

int main(int argc, char const *argv[])
{
    iosb;
    // freopen("a.txt", "r", stdin);
    vector<int> nums = {0, 2, 2, 1, 1};
    sort(begin(nums), end(nums));
    int ans = 1;
    for (auto i : nums)
    {
        if (i <= 0)
            continue;
        else if (ans == i)
            ans++;
        else if (i > ans)
            break;
    }
    cout << ans << endl;
    return 0;
}