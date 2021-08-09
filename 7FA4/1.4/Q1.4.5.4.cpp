// Q1.4.5.4. 损坏的打字机
// WzhDnwzWzh

#include <cstdio>
#include <cctype>

struct Node
{
    char v;
    int pre, next;
};

Node type[1000001];

int main()
{
    char str;
    int last = 1, pos = 0;
    type[0].next = type[0].pre = -1;

    while (true)
    {
        str = getchar();
        if (isspace(str))
            break;

        if (str == '[')
        {
            if (type[pos].pre != -1)
                pos = type[pos].pre;
        }
        else if (str == ']')
        {
            if (type[pos].next != -1)
                pos = type[pos].next;
        }
        else if (str == '}')
        {
            if (type[pos].pre != -1)
            {
                type[type[pos].pre].next = type[pos].next;
                type[type[pos].next].pre = type[pos].pre;
                pos = type[pos].pre;
            }
        }
        else
        {
            type[last].v = str;
            type[last].pre = pos;
            type[last].next = type[pos].next;
            type[type[last].next].pre = last;
            type[type[last].pre].next = last;
            pos = last;
            last++;
        }
    }

    for (int i = type[0].next; i != -1; i = type[i].next)
        printf("%c", type[i].v);
    printf("\n");
    return 0;
}