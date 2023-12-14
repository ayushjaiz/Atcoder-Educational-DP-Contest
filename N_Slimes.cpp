#include <bits/stdc++.h>
using namespace std;

#define int long long int

int fun(int left, int right, vector<int> &a, vector<vector<int>> &dp)
{
    if (left == right)
        return 0;

    if (dp[left][right] != -1)
        return dp[left][right];

    int total_size = 0;
    for (int i = left; i <= right; i++)
        total_size += a[i];

    int ans = 1e15;
    for (int b = left + 1; b <= right; b++)
    {
        int res = fun(left, b - 1, a, dp) + fun(b, right, a, dp) + total_size;
        ans = min(ans, res);
    }
    return dp[left][right] = ans;
}

int32_t main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << fun(0, n - 1, a, dp);

    return 0;
}
