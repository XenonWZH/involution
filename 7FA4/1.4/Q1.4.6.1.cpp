// Q1.4.6.1. 排队2
// WzhDnwzWzh

#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int v, pre, next;
} kid[1001];

int main()
{
    int n, m, i, j, k, a, p = 0, pos;

    cin >> n;
    for (int each = 1; each <= n; each++)
    {
        kid[each].v = each;
        kid[each].pre = kid[each].next = -1;
    }
    cin >> m;
    for (int each = 0; each < m; each++)
    {
        cin >> i >> j >> a;

        for (pos = j, k = 0; kid[pos].next != -1 && k < a; pos = kid[pos].next, k++);
        if (kid[j].pre != -1)
            kid[kid[j].pre].next = kid[pos].next;
        if (kid[pos].next != -1)
            kid[kid[pos].next].pre = kid[j].pre;
        kid[j].pre = i;
        if (kid[i].next != -1)
            kid[kid[i].next].pre = pos;
        kid[pos].next = kid[i].next;
        kid[i].next = j;
    }

    for (int each = 1; each <= n; each++)
        if (kid[each].pre == -1)
            p++;
    cout << p << endl;
    for (int each = 1; each <= n; each++)
        if (kid[each].pre == -1)
        {
            for (int pos = each; pos != -1; pos = kid[pos].next)
                cout << kid[pos].v << " ";
            cout << endl;
        }
    return 0;
}