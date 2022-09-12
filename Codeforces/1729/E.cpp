#include <cstdio>
#include <iostream>

int main() {
    long long a;
    for (int i = 2; i <= 25; i++) {
        printf("? 1 %d\n", i);
        fflush(stdout);
        scanf("%lld", &a);
        if (a == -1) {
            printf("! %d\n", i - 1);
            return 0;
        }
        printf("? %d 1\n", i);
        fflush(stdout);
        long long b;
        scanf("%lld", &b);
        if (b != a) {
            printf("! %lld\n", b + a);
            fflush(stdout);
            return 0;
        }
    }
    return 0;
}