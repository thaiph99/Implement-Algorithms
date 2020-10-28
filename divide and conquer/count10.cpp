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

// Function to count binary strings
// that satisfy the given condition

int cntBinStr(int N, int P, int Q)
{
    int zero[N + 1][P];
    int one[N + 1][Q];
    memset(zero, 0, sizeof(zero));
    memset(one, 0, sizeof(one));
    zero[1][1] = one[1][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j < P; j++)
            zero[i][j] = zero[i - 1][j - 1];
        for (int j = 1; j < Q; j++)
            zero[i][1] = zero[i][1] + one[i - 1][j];
        for (int j = 2; j < Q; j++)
            one[i][j] = one[i - 1][j - 1];
        for (int j = 1; j < P; j++)
            one[i][1] = one[i][1] + zero[i - 1][j];
    }
    int res = 0;
    FOR(i, 1, N)
    {
        FOR(j, 1, P - 1)
        {
            cout << zero[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n-------" << endl;
    FOR(i, 1, N)
    {
        FOR(j, 1, Q - 1)
        cout << one[i][j] << " ";
        cout << endl;
    }
    cout << "\n-------" << endl;
    // Count binary strings of
    // length N having less than
    // P consecutive 0s
    for (int i = 1; i < P; i++)
        res = res + zero[N][i];

    // Count binary strings of
    // length N having less than
    // Q consecutive 1s
    for (int i = 1; i < Q; i++)
        res = res + one[N][i];
    return res;
}

// Driver Code
int main()
{
    int N = 5, P = 3, Q = 4;
    cout << cntBinStr(N, P, Q);
    return 0;
}
