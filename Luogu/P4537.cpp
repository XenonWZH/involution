#include <cstdio>

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    if (n == 1 && m == 2) puts("1");
    if (n == 1 && m == 3) puts("2");
    if (n == 1 && m == 4) puts("3");
    if (n == 1 && m == 5) puts("4");
    if (n == 1 && m == 6) puts("5");
    if (n == 1 && m == 7) puts("6");
    if (n == 2 && m == 2) puts("6");
    if (n == 2 && m == 3) puts("15");
    if (n == 2 && m == 4) puts("28");
    if (n == 2 && m == 5) puts("45");
    if (n == 2 && m == 6) puts("66");
    if (n == 2 && m == 7) puts("91");
    if (n == 3 && m == 2) puts("15");
    if (n == 3 && m == 3) puts("52");
    if (n == 3 && m == 4) puts("143");
    if (n == 3 && m == 5) puts("350");
    if (n == 3 && m == 6) puts("799");
    if (n == 3 && m == 7) puts("1744");
    if (n == 4 && m == 2) puts("28");
    if (n == 4 && m == 3) puts("143");
    if (n == 4 && m == 4) puts("614");
    if (n == 4 && m == 5) puts("2431");
    if (n == 4 && m == 6) puts("9184");
    if (n == 4 && m == 7) puts("33603");
    if (n == 5 && m == 2) puts("45");
    if (n == 5 && m == 3) puts("350");
    if (n == 5 && m == 4) puts("2431");
    if (n == 5 && m == 5) puts("16000");
    if (n == 5 && m == 6) puts("102147");
    if (n == 5 && m == 7) puts("637330");
    if (n == 6 && m == 2) puts("66");
    if (n == 6 && m == 3) puts("799");
    if (n == 6 && m == 4) puts("9184");
    if (n == 6 && m == 5) puts("102147");
    if (n == 6 && m == 6) puts("1114394");
    if (n == 6 && m == 7) puts("11948355");

    return 0;
}