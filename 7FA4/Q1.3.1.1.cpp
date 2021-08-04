// Q1.3.1.1. 消灭或且非
// WzhDnwzWzh

#include <cstdio>

int main()
{
	int T;

	scanf("%d", &T);

	while(T > 0)
    {
		int ia, ib, ic, id;

		scanf("%d%d%d%d", &ia, &ib, &ic, &id);
		bool a = ia == 1, b = ib == 1, c = ic == 1, d = id == 1;
        bool f = true;

        if (a)
        {
            if (b)
            {
                printf("A is true.\n");
                f = false;
            }
            else
            {
                if (c);
                else if (d)
                {
                    printf("A is true.\n");
                    f = false;
                }
            }
        }
        else
        {
            if (c);
            else if (d)
            {
                printf("A is true.\n");
                f = false;
            }
        }
        if (a)
        {
            if (c);
            else if (d)
            {
                printf("B is ture.\n");
                f = false;
            }
        }
        else if (b);
        else
        {
            if (c);
            else if (d)
            {
                printf("B is ture.\n");
                f = false;
            }
        }
		if (f)
            printf("A and B are false.\n");
        T--;
	}
	return 0;
}