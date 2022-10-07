// 272 - TEX Quotes
// WzhDnwzWzh

#include <cstdio>

using namespace std;

int main()
{
    char c;
    bool first = true;

    while (scanf("%c", &c) != EOF)
    {
        if (c == '\"')
        {
            if (first)
                printf("``");
            else
                printf("''");
            first = !first;
        }
        else
            printf("%c", c);
    }

    return 0;
}