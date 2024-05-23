#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int mod = 1e9 + 7;
int add(int a, int b) { return (((a % mod + b % mod) % mod) + mod) % mod; }
int mul(int a, int b) { return (((a % mod * b % mod) % mod) + mod) % mod; }

int dp[100000][2];

int dfs(int node, int parent, int my_color, vector<int> edges[])
{
    if (dp[node][my_color] != -1)
        return dp[node][my_color];

    int ans = 1;
    for (auto child : edges[node])
    {
        if (child == parent)
            continue;

        int temp = 0;
        temp = add(temp, dfs(child, node, 0, edges));

        // if i am white, i can paint child white also
        if (my_color == 0)
            temp = add(temp, dfs(child, node, 1, edges));

        ans = mul(temp, ans);
    }
    return dp[node][my_color] = ans;
}

int32_t main() 
{
    int n;
    cin >> n;

    vector<int> edges[n];
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    memset(dp, -1, sizeof(dp));

    cout << add(dfs(0, -1, 0, edges), dfs(0, -1, 1, edges)) << endl;
}
