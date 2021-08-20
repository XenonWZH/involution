// Q1.4.5.3. 约瑟夫问题
// WzhDnwzWzh

#include <iostream>
#include <list>

using namespace std;

struct Node
{
    int v, pre, next;
} people[100001];

int main()
{
    int n, m, pos = 1;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        people[i].v = i;
        people[i].pre = i - 1;
        people[i].next = i + 1;
    }
    people[1].pre = n;
    people[n].next = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
            pos = people[pos].next;
        cout << pos << endl;
        people[people[pos].pre].next = people[pos].next;
        people[people[pos].next].pre = people[pos].pre;
        pos = people[pos].next;
    }

    cout << pos << endl;
    return 0;
}