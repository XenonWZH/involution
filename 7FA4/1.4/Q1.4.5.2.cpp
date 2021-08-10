// Q1.4.5.2. 排队1
// WzhDnwzWzh

#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int v, pre, next;
};

struct Que
{
    Node kid[2001];
    int len;
    Que()
    {
        kid[0].next = 1;
        kid[0].pre = -1;
        kid[1].next = -1;
        kid[1].pre = 0;
        len = 1;
    }
} kids[1001];

bool comp(Que a, Que b)
{
    int pos, len_a = 0, len_b = 0;
    if (a.kid[0].next == -1 && b.kid[0].next != -1)
        return true;
    if (a.kid[0].next != -1 && b.kid[0].next == -1)
        return false;
    if (a.kid[0].next == -1 && b.kid[0].next == -1)
        return false;
    return a.kid[a.kid[0].next].v < b.kid[b.kid[0].next].v;
}

int main()
{
    int n, m, x, y, pos_x[2], pos_y[2], pos, cnt;

    cin >> n >> m;
    cnt = n;
    for (int i = 1; i <= n; i++)
    {
        kids[i].kid[1].v = i;
        kids[i].len = 2;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;

        for (int j = 1; j <= n; j++)
        {
            for (pos = kids[j].kid[0].next; kids[j].kid[pos].v != x && kids[j].kid[pos].next != -1; pos = kids[j].kid[pos].next);
            if (kids[j].kid[pos].v == x)
            {
                pos_x[0] = j;
                pos_x[1] = pos;
            }
            for (pos = kids[j].kid[0].next; kids[j].kid[pos].v != y && kids[j].kid[pos].next != -1; pos = kids[j].kid[pos].next);
            if (kids[j].kid[pos].v == y)
            {
                pos_y[0] = j;
                pos_y[1] = pos;
            }
        }
        kids[pos_x[0]].kid[kids[pos_x[0]].len].v = kids[pos_y[0]].kid[pos_y[1]].v;
        kids[pos_x[0]].kid[kids[pos_x[0]].len].pre = pos_x[1];
        kids[pos_x[0]].kid[kids[pos_x[0]].len].next = kids[pos_x[0]].kid[pos_x[1]].next;
        kids[pos_x[0]].kid[kids[pos_x[0]].kid[pos_x[1]].next].pre = kids[pos_x[0]].len;
        kids[pos_x[0]].kid[pos_x[1]].next = kids[pos_x[0]].len++;
        kids[pos_y[0]].kid[kids[pos_y[0]].kid[pos_y[1]].pre].next = kids[pos_y[0]].kid[pos_y[1]].next;
        kids[pos_y[0]].kid[kids[pos_y[0]].kid[pos_y[1]].next].pre = kids[pos_y[0]].kid[pos_y[1]].pre;
        if (kids[pos_y[0]].kid[0].next == -1)
            cnt--;
    }
    sort(kids + 1, kids + n, comp);

    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
        if (kids[i].kid[0].next != -1)
        {
            for (pos = kids[i].kid[0].next; pos != -1; pos = kids[i].kid[pos].next)
                cout << kids[i].kid[pos].v << " ";
            cout << endl;
        }
    return 0;
}