#include <bits/stdc++.h>
using namespace std;
#define int long long int

int inf = 1e18;
int score[16];
int SquareGroupSum[1 << 16];
int dp[(1 << 16)][16];
int n, d;

void prepareSquareGroupSum()
{
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0)
                ans += score[i] * score[i];
        }
        SquareGroupSum[mask] = ans;
    }
}

int solve(int mask, int d)
{
    if (mask == 0)
        return dp[mask][d]= 0;

    if (__builtin_popcountll(mask) <= d)
    {
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0)
                return solve((mask ^ (1 << i)), d - 1);
        }
    }

    if (dp[mask][d] != inf)
        return dp[mask][d];

    int ans = inf;
    for (int submask = mask; submask != 0; submask = mask & (submask - 1))
        ans = min(ans, SquareGroupSum[submask] + solve((mask ^ submask), d - 1));

    return dp[mask][d] = ans;
}
int32_t main()
{
    cin >> n >> d;

    for (int i = 0; i < n; i++)
        cin >> score[i];

    prepareSquareGroupSum();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < d + 1; j++)
            dp[i][j] = inf;

    cout << n << " " << d << endl;

    cout << solve((1 << n) - 1, d);

    return 0;
}
