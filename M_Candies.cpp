#include <bits/stdc++.h>
using namespace std;

#define int long long int

int mod = 1e9 + 7;

int add(int a, int b) { return (((a % mod + b % mod) % mod) + mod) % mod; }
int subtract(int a, int b) { return (((a % mod - b % mod) % mod) + mod) % mod; }

int32_t main()
{
    int n, K;
    cin >> n >> K;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(K + 1, 0));

    // number of ways of distributing k candies among n children: dp[n][k]

    for (int k = 1; k <= K; k++)
        dp[0][k] = 0;

    for (int childrens = 0; childrens <= n; childrens++)
        dp[childrens][0] = 1;

    for (int idx = 1; idx <= n; idx++)
    {
        vector<int> prefix(K + 1, 1);

        for (int k = 1; k <= K; k++)
            prefix[k] = add(prefix[k - 1], dp[idx - 1][k]);

        for (int k = 1; k <= K; k++)
        {
            if (k <= a[idx])
                dp[idx][k] = prefix[k];
            else
                dp[idx][k] = subtract(prefix[k], prefix[k - a[idx] - 1]);
        }
    }
    cout << dp[n][K];

    return 0;
}
