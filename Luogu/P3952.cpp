// P3952 [NOIP2017 提高组] 时间复杂度
// WzhDnwzWzh

#include <iostream>
#include <cstring>

using namespace std;

struct Node
{
    string str, x, y;
};

int main()
{
    int t, l, o, nx, ny, unshown;
    string tmp;
    Node stack[100];
    int depth, top, maxn;
    bool err, f[100];
    memset(f, 0, sizeof(f));

    cin >> t;
    while (t > 0)
    {
        top = depth = maxn = 0;
        unshown = 100;
        err = false;

        cin >> l >> tmp;
        if (tmp[2] == '1')
            o = 0;
        else
        {
            o = 0;
            for (int each = 4; tmp[each] >= '0' && tmp[each] <= '9'; each++)
                o = o * 10 + tmp[each] - '0';
        }
        for (int each = 0; each < l; each++)
        {
            cin >> tmp;
            if (tmp == "F")
            {
                cin >> stack[top].str >> stack[top].x >> stack[top].y;

                for (int j = 0; j < top; j++)
                    if(stack[j].str == stack[top].str)
                        err = true;
                if (stack[top].x == "n" && stack[top].y == "n")
                    f[top] = false;
                if (stack[top].x == "n" && stack[top].y != "n")
                {
                    f[top] = false;
                    if (top < unshown)
                        unshown = top;
                }
                if (stack[top].x != "n" && stack[top].y == "n")
                {
                    if (top < unshown)
                    {
                        f[top] = true;
                        depth++;
                    }
                    else
                        f[top] = false;
                }
                if (stack[top].x != "n" && stack[top].y != "n")
                {
                    nx = ny = 0;
                    for (int j = 0; j < stack[top].x.length(); j++)
                        nx = nx * 10 + stack[top].x[j] - '0';
                    for (int j = 0; j < stack[top].y.length(); j++)
                        ny = ny * 10 + stack[top].y[j] - '0';
                    if (nx > ny && top < unshown)
                        unshown = top;
                    f[top] = false;
                }
                top++;
                if (depth > maxn)
                    maxn = depth;
            }
            else
            {
                if (top == 0)
                    err = true;
                else
                {
                    if (top - 1 == unshown)
                        unshown = 100;
                    else if (f[top - 1])
                        depth--;
                    top--;
                }
            }
        }

        if (err || top != 0)
            cout << "ERR" << endl;
        else if (maxn == o)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        t--;
    }

    return 0;
}