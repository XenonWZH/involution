// UVA1225 数数字 Digit Counting
// WzhDnwzWzh

#include <cstdio>
#include <cstring>

int main()
{
    int n, num, cha[10];
    char str[10];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        memset(cha, 0, sizeof(cha));
        scanf("%d", &num);

        for (int j = 1; j <= num; j++)
        {
            sprintf(str, "%d", j);
            for (int k = 0; k < strlen(str); k++)
                cha[str[k] - '0']++;
        }

        for (int i = 0; i <= 8; i++)
            printf("%d ", cha[i]);
        printf("%d\n", cha[9]);
    }

    return 0;
}