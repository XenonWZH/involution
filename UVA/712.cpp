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
    char tree[1 << 7], c;
    string str;

    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        getchar();

        for (int i = 0; i < n; i++)
            cin >> str;
        getchar();
        for (int i = pow(2, n); i < pow(2, n + 1); i++)
            tree[i] = getchar();
        scanf("%d", &m);
        getchar();
        str = "";
        for (int i = 0; i < m; i++)
        {
            pos = 1;
            for (int j = 1; j <= n; j++)
            {
                c = getchar();
                pos *= 2;
                if (c == '1')
                    pos++;
            }
            str += tree[pos];
            getchar();
        }

        printf("S-Tree #%d\n", ++cnt);
        cout << str << endl << endl;
    }

    exit(0);
}