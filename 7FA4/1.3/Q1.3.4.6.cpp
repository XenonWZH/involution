// Q1.3.4.6. 并查集
// WzhDnwzWzh

#include <iostream>

using namespace std;

struct Node
{
    int v = -1, father = {-1}, son[2] = {-1, -1};
};

Node tree[2005];
int len;

void merge(int x, int y)
{
    int pos;
    len++;
    for (pos = x; tree[pos].father != -1; pos = tree[pos].father);
    tree[len].son[0] = pos;
    for (pos = y; tree[pos].father != -1; pos = tree[pos].father);
    tree[len].son[1] = pos;
    tree[x].father = tree[y].father = len;
}

bool search(int pos, int x)
{
    if (tree[pos].v == x)
        return true;
    if (tree[pos].son[0] == -1 && tree[pos].son[1] == -1)
        return false;
    return search(tree[pos].son[0], x) || search(tree[pos].son[1], x);
}

bool find(int x, int y)
{
    int pos;
    for (pos = x; tree[pos].father != -1; pos = tree[pos].father);
    return search(pos, y);
}

int main()
{
    int n, m, t, x, y;

    cin >> n >> m;
    len = n;
    for (int i = 1; i <= n; i++)
        tree[i].v = i;
    for (int i = 0; i < m; i++)
    {
        cin >> t >> x >> y;

        if (t == 0)
            merge(x, y);
        if (t == 1)
            cout << (int)find(x, y) << endl;
    }

    return 0;
}