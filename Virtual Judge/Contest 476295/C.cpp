// C - 奖学金
// XenonWZH

#include <iostream>
#include <algorithm>

const int MAXN = 300;

struct Student {
    int id, ch, ma, en, score;
} students[MAXN];

bool comp(Student a, Student b) {
    if (a.score != b.score) return a.score > b.score;
    if (a.ch != b.ch) return a.ch > b.ch;
    return a.id < b.id;
}

int main() {
    int n;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        students[i].id = i + 1;
        std::cin >> students[i].ch >> students[i].ma >> students[i].en;
        students[i].score = students[i].ch + students[i].ma + students[i].en;
    }

    std::sort(students, students + n, comp);

    for (int i = 0; i < 5; i++) {
        std::cout << students[i].id << " " << students[i].score << std::endl;
    }

    return 0;
}