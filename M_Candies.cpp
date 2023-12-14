#include <bits/stdc++.h>
using namespace std;

#define int long long int

int mod = 1e9 + 7;

int add(int a, int b) { return (((a % mod + b % mod) % mod) + mod) % mod; }
int subtract(int a, int b) { return (((a % mod - b % mod) % mod) + mod) % mod; }

int32_t main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for (int i = 0; i <= a[0] and i <= k; i++)
        dp[0][i] = 1;

    for (int i = 1; i < n; i++)
    {
        vector<int> prefix(k + 1);
        prefix[0] = dp[i - 1][0];

        for (int j = 1; j <= k; j++)
            prefix[j] = add(prefix[j - 1], dp[i - 1][j]);

        for (int j = 0; j <= k; j++)
        {
            if (j > a[i])
                dp[i][j] = subtract(prefix[j], prefix[j - a[i] - 1]);
            else
                dp[i][j] = prefix[j] % mod;
        }
    }
    cout << dp[n - 1][k];

    return 0;
}
