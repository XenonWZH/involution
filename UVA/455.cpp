// UVA455 周期串 Periodic Strings
// WzhDnwzWzh

#include <cstdio>
#include <cstring>

int main()
{
    int n;
    char str[81];
    bool right;

    scanf("%d", &n);
    while (n > 0)
    {
        scanf("%s", str);

        for (int i = 1; i <= strlen(str); i++)
        {
            right = true;
            for (int j = 0; j < i; j++)
                for (int k = j; k < strlen(str); k += i)
                    if (str[k] != str[j])
                        right = false;

            if (right)
            {
                printf("%d\n", i);
                if (n > 1)
                    printf("\n");
                break;
            }
        }

        n--;
    }

    return 0;
}