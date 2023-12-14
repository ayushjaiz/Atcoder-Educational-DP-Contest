#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> chance(n);
    for (int i = 0; i < n; i++)
        cin >> chance[i];

    vector<int> dp(k + 1);
    dp[0] = 0;

    for (int idx = 1; idx <= k; idx++)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (idx - chance[i] < 0)
                continue;

            else if (dp[idx - chance[i]] == 0)
            {
                ans = 1;
                break;
            }
        }
        dp[idx] = ans;
    }

    if (dp[k] == 1)
        cout << "First";
    else
        cout << "Second";
}
