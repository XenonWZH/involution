// Q1.5.X.7. 并查集2
// WzhDnwzWzh

#include <iostream>

using namespace std;

int fa[100001];

void make_set(int size)
{
    for (int i = 0; i < size; i++)
        fa[i] = i;
    return;
}

int find(int x)
{
    if (x != fa[x])
        fa[x] = find(fa[x]);
    return fa[x];
}

void union_set(int x, int y)
{
    x = find(x);
    y = find(y);
    fa[x] = y;
}

int main()
{
    int n, m, t, x, y;

    cin >> n >> m;
    make_set(n);
    for (int i = 0; i < m; i++)
    {
        cin >> t >> x >> y;

        if (t == 0)
            union_set(x, y);
        if (t == 1)
            cout << (int)(find(x) == find(y)) << endl;
    }

    return 0;
}