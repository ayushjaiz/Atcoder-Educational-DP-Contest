/* @ayushjaiz */

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
#define PI 3.14159265358979323846

#define int long long int
#define pb push_back
#define endl "\n"
using uii = unordered_map<int, int>;
using mii = map<int, int>;
using vi = vector<int>;
using pii = pair<int, int>;
using si = set<int>;
#define ff first
#define ss second
#define mp make_pair
#define nl cout << "\n"
#define yes cout << "YES "
#define no cout << "NO "
#define pno cout << -1 << " "
#define alice cout << "ALICE "
#define bob cout << "BOB "
#define zz cout << 0 << " "
#define dbg(var) cout << #var << "=" << var << " "
using maxheap = priority_queue<int>;
using minheap = priority_queue<int, vector<int>, greater<int>>;

#define ceild(a, b) (a + b - 1) / b // a is divided by b
#define ceil2(n) (n + 1LL) >> 1LL
#define odd(i) i & 1
#define even(i) !(i & 1)
#define rev greater<int>()
#define lb lower_bound
#define ub upper_bound
#define setpr(x) cout << setprecision(x) << fixed
#define setbits(x) __builtin_popcountll(x)
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define yrn(condition) cout << (condition ? "YES " : "NO ")

#define fo(i, a, b) for (int i = a; i < b; ++i)
#define fl(i, a, b) for (int i = a; i <= b; ++i)
#define rl(i, a, b) for (int i = a; i >= b; --i)
#define all(v) v.begin(), v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vmax(a) *max_element(a.begin(), a.end())
#define vmin(a) *min_element(a.begin(), a.end())

void vprint(vector<int> &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
void sprint(set<int> &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
void mprint(map<int, int> &v)
{
    for (auto it : v)
        cout << it.ff << " " << it.ss << endl;
}
int vsum(vector<int> &v)
{
    int sum = 0;
    for (auto it : v)
        sum += it;
    return sum;
}
vector<int> psum(vector<int> &v)
{
    vector<int> ans;
    int s = 0;
    ans.push_back(0);
    for (int i = 0; i < v.size(); i++)
    {
        s += v[i];
        ans.push_back(s);
    }
    return ans;
}
void vin(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cin >> v[i];
}

int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, -1, 1, 1, 1, -1, -1};

// NUMBERS

int countdigits(int n)
{
    int s = 0;
    while (n != 0)
    {
        s++;
        n = n / 10;
    }
    return s;
}
int sumdigits(int n)
{
    int s = 0;
    while (n != 0)
    {
        s += n % 10;
        n = n / 10;
    }
    return s;
}
int exp(int a, int b) // a^b
{
    int ans = 1;
    while (b)
    {
        if (b & 1LL)
            ans = (ans * 1LL * a) % mod;
        a = (a * 1LL * a) % mod, b = b >> 1LL;
    }
    return ans;
}

// sieve();
vector<int> primes;
void sieve(int n = 100000) // primes till n
{
    int i, j;
    vector<int> a(n + 1, 0);
    for (int i = 3; i <= n; i += 2)
        a[i] = 1;
    a[2] = 1;
    for (i = 3; i * i <= n; i = i + 2)
    {
        for (j = i * i; j <= n; j += 2 * i)
            if (a[j])
                a[j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        if (a[i])
            primes.emplace_back(i);
    }
}

// call this after sieve
map<int, int> mapping_primes(int m) // mapping primes by sieve
{
    int i = 0;
    map<int, int> ans;
    while (primes[i] * primes[i] <= m)
    {
        if (m % primes[i] == 0)
        {
            int count = 0;
            while (m % primes[i] == 0)
                count++, m /= primes[i];
            ans.insert({primes[i], count}); //----------
        }
        i++;
    }
    if (m != 1)
        ans.insert({m, 1}); //--------

    return ans;
}

bool is_prime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

// call this after sieve
vector<int> prime_factorization(int n)
{
    int i = 0, m = n;
    vector<int> ans;
    while (primes[i] * primes[i] <= m)
    {
        if (m % primes[i] == 0)
        {
            int count = 0;
            while (m % primes[i] == 0)
            {
                count++, m /= primes[i];
                ans.push_back(primes[i]);
            }
        }
        i++;
    }
    if (m != 1)
        ans.push_back(m);
    return ans;
}

vector<int> factors(int m)
{
    vector<int> ans;
    for (int i = 1; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            ans.push_back(i);
            if (i != m / i)
                ans.push_back(m / i);
        }
    }
    return ans;
}

vector<int> fact, modinv;
void precomp(int n = 1000000)
{
    fact.resize(n + 1);
    modinv.resize(n + 1);
    fact[0] = 1, modinv[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * 1LL * i) % mod,
        modinv[i] = exp(fact[i], mod - 2);
}
// call this after precomp
int ncr(int n, int r)
{
    if (r > n || n == 0)
        return 0;
    int numo = fact[n], invdeno = (modinv[r] * 1LL * modinv[n - r]) % mod;
    return (numo * 1LL * invdeno) % mod;
}

static bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first != b.first)
        return a.first < b.first;

    return a.second > b.second;
}

bool is_sorted(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] < a[i - 1])
            return false;
    }
    return true;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int lowpowerof2(int n) { return 1LL << (int)log2(n); }
int highpowerof2(int n) { return 1LL << (int)ceil(log2(n)); }
bool ispowerof2(int n) { return (n != 0) && ((n & (n - 1)) == 0); }
int inverse(int a, int b) { return exp(a, b - 2); }

int mul(int a, int b) { return (((a % mod * b % mod) % mod) + mod) % mod; }
int add(int a, int b) { return (((a % mod + b % mod) % mod) + mod) % mod; }
int sub(int a, int b) { return (((a % mod - b % mod) % mod) + mod) % mod; }
int divide(int a, int b) { return (((a % mod * 1ll * exp(b, mod - 2)) % mod) + mod) % mod; }

// STRING

int is_substring(string &s1, string &s2) // s1 is present in s2?
{
    if (s2.find(s1) != string::npos)
        return true; // s2.find(s1)
    return false;    // -1
}
bool is_palindrome(string &s)
{
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return (s1 == s);
}
string decimaltobinary(int n)
{
    string s;
    while (n)
        s += (n & 1LL) + '0', n = n >> 1LL;
    reverse(s.begin(), s.end());
    return s;
}
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define toupper(s) transform(s.begin(), s.end(), s.begin(), ::toupper)

void solve();
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "\nCase " << i << ":\n";
        solve();
        cout << endl;
    }
    return 0;
}

long double fix = -1.0;

long double fun(int idx, int rem, vector<vector<long double>> &dp, vector<long double> &a)
{
    // cout << idx << " " << rem << "----->" << dp[idx][rem] << " ";

    if (idx == 0)
        return 1.0;

    if (dp[idx][rem] != fix)
        return dp[idx][rem];

    long double take = 0.0;
    if (rem > 0)
        take = a[idx] * fun(idx - 1, rem - 1, dp, a);

    long double notake = 0.0;
    if (idx - 1 >= rem)
        notake = (1.0 - a[idx]) * fun(idx - 1, rem, dp, a);

    // cout << idx << "-" << take << " " << notake << endl;

    return dp[idx][rem] = take + notake;
}
void solve()
{
    int n;
    cin >> n;

    vector<long double> a(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // cout << a[i] << " ";
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     // cin >> a[i];
    //     cout << a[i] << " ";
    // }
    // nl;

    vector<vector<long double>> dp(n + 1, vector<long double>(n + 1, fix));

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     nl;
    // }

    // cout << fun(n, 1, dp, a);

    int heads = (n + 1) / 2;
    // cout << heads;

    long double ans = 0.0;
    for (int i = n; i >= heads; i--)
    {
        ans += fun(n, i, dp, a);
    }
    cout << fixed << setprecision(10) << ans;
}
