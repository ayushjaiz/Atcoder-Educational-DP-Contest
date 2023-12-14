#include <bits/stdc++.h>
using namespace std;
#define int long long int

int dp[101][100001];
int suffix[105];
int n, mod = 1e9 + 7;
vector<int> a(101);

int fun(int idx, int rem)
{
    if (idx == n)
        return rem == 0;

    if (dp[idx][rem] != -1)
        return dp[idx][rem];

    if (suffix[idx] == rem)
        return dp[idx][rem] = 1;

    int ans = 0;
    for (int i = 0; i <= a[i]; i++)
    {
        if (i > rem)
            break;

        ans += fun(idx + 1, rem - a[idx]);
        ans %= mod;
    }

    return dp[idx][rem] = ans;
}
int32_t main()
{
    int k;
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
        sum += a[i], suffix[i] = sum;

    cout << fun(0, k);
}

