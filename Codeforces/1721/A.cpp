#include <cstdio>
#include <map>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        char str[2][sizeof("aa")];
        scanf("%s", str[0]);
        scanf("%s", str[1]);

        std::map<char, int> m;
        m[str[0][0]]++, m[str[0][1]]++, m[str[1][0]]++, m[str[1][1]]++;

        printf("%ld\n", m.size() - 1);
    }

    return 0;
}