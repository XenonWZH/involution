// P1030 [NOIP2001 普及组] 求先序排列
// WzhDnwzWzh

#include <iostream>
#include <string>

struct Node {
    int fa, son[2], v;
} tree[10];

void getTop() {}

void travMid(std::string mid, std::string last) {
    if (mid.size() > 0) {
        std::cout << last[last.size() - 1];

        int pos = mid.find(last[last.size() - 1]);
        travMid(mid.substr(0, pos), last.substr(0, pos));
        travMid(mid.substr(pos + 1, mid.size() - 1), last.substr(pos, mid.size() - pos - 1));
    }
}

int main() {
    std::string mid, last;

    std::cin >> mid >> last;

    travMid(mid, last);

    std::cout << std::endl;
    return 0;
}
