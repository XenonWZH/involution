// Q2.2.5.3. 数塔问题（DEBUG）
// WzhDnwzWzh

#include <cstdio>
#include <cstring>

const int N = 1009;

int a[N][N], f[N][N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);

    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= n; j++)
        {
            if (f[i + 1][j] > f[i + 1][j + 1])
                f[i][j] = f[i + 1][j] + a[i][j];
            else
                f[i][j] = f[i + 1][j + 1] + a[i][j];
        }

    printf("%d\n", f[1][1]);
    return 0;
}