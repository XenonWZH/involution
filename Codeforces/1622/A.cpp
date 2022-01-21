#include <cstdio>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int l1, l2, l3;

        scanf("%d%d%d", &l1, &l2, &l3);

        if (l1 == l2 + l3 || l2 == l1 + l3 || l3 == l1 + l2) printf("YES\n");
        else if ((l1 == l2 && l3 % 2 == 0) || (l1 == l3 && l2 % 2 == 0) || 
                 (l2 == l3 && l1 % 2 == 0)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}