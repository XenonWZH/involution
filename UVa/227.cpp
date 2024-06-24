#include <iostream>
#include <string>

int t = 0;
std::string a[5];

int main() {
    while (true) {
        while (true) {
            std::getline(std::cin, a[0]);
            if (a[0] != "") break;
        }
        if (a[0] == "Z") break;
        for (int i = 1; i < 5; i++) {
            std::getline(std::cin, a[i]);
            if (a[i].length() == 4) a[i] += ' ';
        }

        bool vaild = true;
        int x, y;
        for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) if (a[i][j] == ' ') x = i, y = j;

        std::string s;
        while (std::cin >> s) {
            int n = s.length();
            bool con = true;

            for (int i = 0; i < n; i++) {
                if (s[i] == '0') {
                    con = false;
                    break;
                } else if (vaild) {
                    if (s[i] == 'A') {
                        if (x == 0) vaild = false;
                        else {
                            a[x][y] = a[x - 1][y], a[x - 1][y] = ' ';
                            x--;
                        }
                    } else if (s[i] == 'B') {
                        if (x == 4) vaild = false;
                        else {
                            a[x][y] = a[x + 1][y], a[x + 1][y] = ' ';
                            x++;
                        }
                    } else if (s[i] == 'L') {
                        if (y == 0) vaild = false;
                        else {
                            a[x][y] = a[x][y - 1], a[x][y - 1] = ' ';
                            y--;
                        }
                    } else if (s[i] == 'R') {
                        if (y == 4) vaild = false;
                        else {
                            a[x][y] = a[x][y + 1], a[x][y + 1] = ' ';
                            y++;
                        }
                    } else vaild = false;
                }
            }

            if (!con) break;
        }

        if (t != 0) std::cout << '\n';
        std::cout << "Puzzle #" << ++t << ":\n";
        if (vaild) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 4; j++) std::cout << a[i][j] << ' ';
                std::cout << a[i][4] << '\n';
            }
        } else std::cout << "This puzzle has no final configuration.\n";
    }

    return 0;
}