// 712 - S-Trees
// WzhDnwzWzh

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m, cnt = 0, pos;
    char tree[1 << 8];
    string str, direction;

    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;

        for (int i = 0; i <= n; i++)
            cin >> str;
        for (int i = pow(2, n); i < pow(2, n + 1); i++)
            tree[i] = str[i - pow(2, n)];
        scanf("%d", &m);
        str = "";
        for (int i = 0; i < m; i++)
        {
            pos = 1;
            cin >> direction;

            for (int j = 0; j < n; j++)
            {
                pos *= 2;
                if (direction[j] == '1')
                    pos++;
            }
            str += tree[pos];
        }

        printf("S-Tree #%d:\n", ++cnt);
        cout << str << endl << endl;
    }

    exit(0);
}