// Q1.4.1.5. 最小数
// WzhDnwzWzh

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char n[1001];    
    int s, pos;
    bool mark[1001];
    memset(mark, false, sizeof(mark));

    scanf("%s", n);
    cin >> s;

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < strlen(n) - 1; j++)
        {
            if (!mark[j])
            {
                for (pos = j + 1; mark[pos] == true; pos++);
                if (pos != strlen(n) && n[j] > n[pos])
                {
                    mark[j] = true;
                    goto endd;
                }
            }
        }
        for (int j = strlen(n) - 1; j >= 0; j--)
            if (!mark[j])
            {
                mark[j] = true;
                break;
            }
    endd:;
    }

    for (int i = 0; i < strlen(n); i++)
    {
        if (!mark[i])
            cout << n[i];
    }
    cout << endl;
    return 0;
}