#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 50000;

struct Node {
    int v, p;
} a[MAXN], temp[MAXN];

long long ans = 0;

bool cmp(Node a, Node b) {
    if (a.p > b.p) return true;
    return false;
}

void mergeSort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    long long sumL = 0, sumR = 0;
    for (int i = l; i <= mid; i++) sumL += a[i].p;
    for (int i = mid + 1; i <= r; i++) sumR += a[i].p;

    int i = l, j = mid + 1, p = l;
    while (i <= mid && j <= r) {
        if (a[i].v > a[j].v) {
            ans += a[i].v * ((r - j + 1) * a[i].p - sumR);
            sumL -= a[i].p;
            temp[p++] = a[i++];
        } else {
            ans += a[j].v * (sumL - (mid - i + 1) * a[j].p);
            sumR -= a[j].p;
            temp[p++] = a[j++];
        }
    }

    while (i <= mid) temp[p++] = a[i++];
    while (j <= r) temp[p++] = a[j++];
    for (int i = l; i <= r; i++) a[i] = temp[i];
}

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].v, &a[i].p);
    }

    std::sort(a, a + n, cmp);

    mergeSort(0, n - 1);

    printf("%lld\n", ans);

    return 0;
}