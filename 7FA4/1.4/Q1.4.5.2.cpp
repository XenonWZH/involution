// Q1.4.5.2. 排队1
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
    int n, m, i, j, p;

    cin >> n;
    p = n;
    for (int each = 1; each <= n; each++)
    {
        kid[each].v = each;
        kid[each].pre = kid[each].next = -1;
    }
    cin >> m;
    for (int each = 0; each < m; each++)
    {
        cin >> i >> j;

        if (kid[j].next == -1 && kid[j].pre == -1)
            p--;
        if (kid[j].next != -1)
            kid[kid[j].next].pre = kid[j].pre;
        if (kid[j].pre != -1)
            kid[kid[j].pre].next = kid[j].next;
        kid[j].next = kid[i].next;
        kid[j].pre = i;
        if (kid[i].next != -1)
            kid[kid[i].next].pre = j;
        kid[i].next = j;
    }

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