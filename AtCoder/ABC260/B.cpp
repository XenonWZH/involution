#include <cstdio>
#include <algorithm>

const int MAXN = 1000;

struct Student {
    int id, math, english;
} students[MAXN + 1];

bool cmpX(Student a, Student b) {
    if (a.math != b.math) return a.math > b.math;
    return a.id < b.id;
}

bool cmpY(Student a, Student b) {
    if (a.english != b.english) return a.english > b.english;
    return a.id < b.id;
}

bool cmpZ(Student a, Student b) {
    if (a.math + a.english != b.math + b.english) return a.math + a.english > b.math + b.english;
    return a.id < b.id;
}

bool cmpAns(Student a, Student b) {
    return a.id < b.id;
}

int main() {
    int n, x, y, z;

    scanf("%d %d %d %d", &n, &x, &y, &z);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &students[i].math);
        students[i].id = i;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &students[i].english);

    std::sort(students + 1, students + n + 1, cmpX);
    std::sort(students + x + 1, students + n + 1, cmpY);
    std::sort(students + x + y + 1, students + n + 1, cmpZ);
    std::sort(students + 1, students + x + y + z + 1, cmpAns);

    for (int i = 1; i <= x + y + z; i++) {
        printf("%d\n", students[i].id);
    }

    return 0;
}