// Q1.5.5.6. 火星人
// WzhDnwzWzh

#include <bits/stdc++.h>

using namespace std;

int mars[1000000];

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void reverse(int *a, int *b)
{
    while (a < b)
    {
        swap(a++, b--);
    }
}

bool next_per(int *a, int n)
{
    int *end = a + 1 + n;
    if (end == a + 1)
        return false;
    end--;
    int *p, *pp, *find;
    p = end;
    while (p != a + 1)
    {
        pp = p;
        p--;
        if (*p < *pp)
        {
            find = end;
            while (*find <= *p)
                find--;

            swap(p, find);
            reverse(pp, end);
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m, cnt = 0;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> mars[i];

    do
    {
        if (cnt == m)
            break;
        cnt++;
    } while (next_per(mars, n));

    for (int i = 1; i <= n; i++)
        cout << mars[i] << " ";
    cout << endl;
    return 0;
}