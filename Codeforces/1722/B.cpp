#include <iostream>

int main() {
    int t;

    scanf("%d", &t);

    while (t--) {
        int n;
        std::string str1, str2;

        std::cin >> n;
        std::cin >> str1 >> str2;

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'G') str1[i] = 'B';
            if (str2[i] == 'G') str2[i] = 'B';
        }

        if (str1 == str2) puts("YES");
        else puts("NO");
    }

    return 0;
}