#include <cstdio>
#include <queue>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    std::deque<int> qMin, qMax;
    for (int i = 0; i < k - 1; i++) {
        while (!qMin.empty() && a[qMin.back()] >= a[i]) qMin.pop_back();
        qMin.push_back(i);

        while (!qMax.empty() && a[qMax.back()] <= a[i]) qMax.pop_back();
        qMax.push_back(i);
    }

    std::vector<int> min(n), max(n);
    for (int i = k - 1; i < n; i++) {
        while (!qMin.empty() && qMin.front() <= i - k) qMin.pop_front();
        while (!qMin.empty() && a[qMin.back()] >= a[i]) qMin.pop_back();
        qMin.push_back(i);
        min[i] = a[qMin.front()];

        while (!qMax.empty() && qMax.front() <= i - k) qMax.pop_front();
        while (!qMax.empty() && a[qMax.back()] <= a[i]) qMax.pop_back();
        qMax.push_back(i);
        max[i] = a[qMax.front()];
    }

    for (int i = k - 1; i < n; i++) printf("%d ", min[i]);
    putchar('\n');
    for (int i = k - 1; i < n; i++) printf("%d ", max[i]);
    putchar('\n');

    return 0;
}