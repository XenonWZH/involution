// #3. 复读机
// WzhDnwzWzh

#include <cstdio>

int main() {
    freopen("copycat.in", "r", stdin);
    freopen("copycat.out", "w", stdout);
    int n;
    char num[10000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", num);
        printf("%s\n", num);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}