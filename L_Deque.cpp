#include <bits/stdc++.h>
using namespace std;

#define int long long int
int dp[3001][3001][2];
vector<int> a;
int fun(int l, int r, int turn)
{
    if (l == r)
    {
        if (turn == 0)
            return a[l];
        else if (turn == 1)
            return 0;
    }

    if (dp[l][r][turn] != -1)
        return dp[l][r][turn];

    if (turn == 0)
    {
        int op1 = a[l] + fun(l + 1, r, !turn);
        int op2 = a[r] + fun(l, r - 1, !turn);
        return dp[l][r][turn] = max(op1, op2);
    }
    else if (turn == 1)
    {
        int op1 = fun(l + 1, r, !turn);
        int op2 = fun(l, r - 1, !turn);
        return dp[l][r][turn] = min(op1, op2);
    }
    return dp[l][r][turn];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));
    int n, sum = 0;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    a = arr;

    cout << 2 * fun(0, n - 1, 0) - sum;
    return 0;
}
