#include <bits/stdc++.h>
using namespace std;

#define int long long int

class segment_tree
{
    //*endpoints:
    // segment_tree seg(a, IDENTITY_ELEMENT);
    // seg.query(left, right);

    vector<int> a, tree;
    int n, identity;
    int purpose(int a, int b)
    {
        return max(a, b); // only changes here
    }
    void build_util(int start, int end, int index)
    {
        if (start == end)
        {
            tree[index] = a[start];
            return;
        }
        int mid = (start + end) / 2;

        build_util(start, mid, 2 * index);
        build_util(mid + 1, end, 2 * index + 1);

        tree[index] = purpose(tree[2 * index], tree[2 * index + 1]);
    }
    int query_util(int qs, int qe, int index, int start, int end)
    {
        if (qs <= start and end <= qe)
            return tree[index];

        if (end < qs or qe < start)
            return identity;

        int mid = (start + end) / 2;
        int op1 = query_util(qs, qe, 2 * index, start, mid);
        int op2 = query_util(qs, qe, 2 * index + 1, mid + 1, end);

        return purpose(op1, op2);
    }
    void updatePoint_util(int index, int start, int end, int value, int point)
    {
        if (point < start or end < point)
            return;

        if (start == end)
        {
            tree[index] += value;
            return;
        }

        int mid = (start + end) / 2;
        updatePoint_util(2 * index, start, mid, value, point);
        updatePoint_util(2 * index + 1, mid + 1, end, value, point);

        tree[index] = purpose(tree[2 * index], tree[2 * index + 1]);
    }

public:
    segment_tree(vector<int> &a, int identity)
    {
        this->a = a;
        this->n = a.size();
        this->identity = identity;

        tree.resize(4 * n + 1, identity);

        build_util(0, a.size() - 1, 1);
    }
    int query(int left, int right)
    {
        return query_util(left, right, 1, 0, n - 1);
    }
    void updatePoint(int point, int value)
    {
        updatePoint_util(1, 0, n - 1, value, point);
    }
};

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second > b.second;

    return a.first < b.first;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    vector<pair<int, int>> copya(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
        copya[i] = {a[i], i};

    sort(copya.begin(), copya.end(), comp);

    vector<int> pos(n);
    for (int i = 0; i < n; i++)
        pos[copya[i].second] = i;

    vector<int> count(n, 0);
    segment_tree seg(count, 0);

    for (int i = 0; i < n; i++)
    {
        int position = pos[i];

        int temp = seg.query(0, position - 1);

        seg.updatePoint(position, temp + b[i]);
    }
    cout << seg.query(0, n - 1);
}
