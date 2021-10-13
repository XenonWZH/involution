// Q2.5.2.1. 逆序对
// WzhDnwzWzh

#include <iostream>

long long ans = 0;
int a[500000], t[500000];

void merge(int ll, int rr) {
    if (rr - ll <= 1) return;
    int mid = ll + (rr - ll >> 1);
    merge(ll, mid);
    merge(mid, rr);
    int p = ll, q = mid, s = ll;
    while (s < rr) {
        if (p >= mid || (q < rr && a[p] > a[q])) {
            t[s++] = a[q++];
            ans += mid - p;
        } else
            t[s++] = a[p++];
    }
    for (int i = ll; i < rr; i++) a[i] = t[i];
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> a[i];
    merge(0, n);
    std::cout << ans << std::endl;
    return 0;
}