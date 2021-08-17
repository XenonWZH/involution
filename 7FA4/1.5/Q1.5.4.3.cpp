#include <cstdio>
#include <cctype>

int a;
long long b;
float c;
double d;
char e;
char f[32];

int main()
{
    scanf("%d%lld%f%lf%c", &a, &b, &c, &d, &e);
    while (isspace(e))
        scanf("%c", &e);
    scanf("%s", f);
    printf("a = %d b is %lld\nc equals%.6fand d equals %.12lf\n%c is e\nf = %s\n", a, b, c, d, e, f);
    return 0;
}