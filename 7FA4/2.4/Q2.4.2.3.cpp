#include <cstdio>
#include <functional>
#include <iostream>
#include <algorithm>

const int MAXN = 1000000;

int main() {
    int n;

    std::cin >> n;

    static int heapSmall[MAXN], heapBig[MAXN];
    std::make_heap(heapSmall, heapSmall);
    std::make_heap(heapBig, heapBig, std::greater<int>());
    int mid = 0, lenSmall = 0, lenBig = 0;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        if (x > mid) {
            if (lenBig > lenSmall) {
                heapSmall[lenSmall++] = heapBig[0];
                std::push_heap(heapSmall, heapSmall + lenSmall);
                std::pop_heap(heapBig, heapBig + lenBig--, std::greater<int>());
            }
            heapBig[lenBig++] = x;
            std::push_heap(heapBig, heapBig + lenBig, std::greater<int>());
        } else {
            if (lenSmall > lenBig) {
                heapBig[lenBig++] = heapSmall[0];
                std::push_heap(heapBig, heapBig + lenBig, std::greater<int>());
                std::pop_heap(heapSmall, heapSmall + lenSmall--);
            }
            heapSmall[lenSmall++] = x;
            std::push_heap(heapSmall, heapSmall + lenSmall);
        }

        if (lenBig == lenSmall) mid = (heapBig[0] + heapSmall[0]) >> 1;
        else mid = lenBig > lenSmall ? heapBig[0] : heapSmall[0];

        printf("%d\n", mid);
    }

    return 0;
}