#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <tuple>

const int MAXN = 100000;
const int MAXN_LOG = 17;
const int MAXM = 10000;

struct Node {
    long long h;
    Node *nextA, *nextB;
    std::list<Node *>::iterator it;
} N[MAXN + 1];

int n, logn, f[2][MAXN + 1][MAXN_LOG + 1];
long long g[2][MAXN + 1][MAXN_LOG + 1][3];

inline void prepare() {
    std::list<Node *> list;
    for (int i = 1; i <= n; i++) {
        list.push_back(&N[i]);
        N[i].it = --list.end();
    }

    list.sort([](Node *a, Node *b){ return a->h < b->h; });

    for (int i = 1; i <= n; i++) {
        std::vector<std::pair<long long, Node *>> vec;

        std::list<Node *>::iterator near;
        near = N[i].it, near++;

        if (near != list.end()) {
            vec.push_back(std::make_pair(std::abs((*near)->h - N[i].h), *near));
            if (++near != list.end()) vec.push_back(std::make_pair(std::abs((*near)->h - N[i].h), *near));
        }

        near = N[i].it;
        if (near != list.begin()) {
            near--;
            vec.push_back(std::make_pair(std::abs((*near)->h - N[i].h), *near));

            if (near != list.begin()) {
                near--;
                vec.push_back(std::make_pair(std::abs((*near)->h - N[i].h), *near));
            }
        }

        std::sort(vec.begin(), vec.end(), [](const std::pair<long long, Node *> &a, const std::pair<long long, Node *> &b) {
            return a.first == b.first ? a.second->h < b.second->h : a.first < b.first;
        });

        if (vec.size() >= 2) {
            N[i].nextA = vec[1].second;
        } else N[i].nextA = &N[0];

        if (vec.size() >= 1) {
            N[i].nextB = vec[0].second;
        } else N[i].nextB = &N[0];

        list.erase(N[i].it);
    }
    N[0].nextA = N[0].nextB = &N[0];

    for (int i = 1; i <= n; i++) {
        f[0][i][0] = N[i].nextA - N;
        f[0][i][1] = N[i].nextA->nextB - N;

        f[1][i][0] = N[i].nextB - N;
        f[1][i][1] = N[i].nextB->nextA - N;

        g[0][i][0][0] = g[0][i][0][2] = N[i].nextA == &N[0] ? 0 : std::abs(N[i].h - N[i].nextA->h);
        g[0][i][0][1] = 0;

        g[1][i][0][1] = g[1][i][0][2] = N[i].nextB == &N[0] ? 0 : std::abs(N[i].h - N[i].nextB->h);
        g[1][i][0][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        g[0][i][1][0] = g[0][i][0][0];
        g[0][i][1][1] = g[1][N[i].nextA - N][0][1];
        g[0][i][1][2] = g[0][i][0][0] + g[1][N[i].nextA - N][0][1];

        g[1][i][1][1] = g[1][i][0][1];
        g[1][i][1][0] = g[0][N[i].nextB - N][0][0];
        g[1][i][1][2] = g[1][i][0][1] + g[0][N[i].nextB - N][0][0];
    }

    while ((1 << logn) <= n) logn++;
    logn--;

    for (int j = 2; j <= logn; j++) {
        for (int i = 1; i <= n; i++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 3; l++) {
                    g[k][i][j][l] = g[k][i][j - 1][l] + g[k][f[k][i][j - 1]][j - 1][l];
                }
                f[k][i][j] = f[k][f[k][i][j - 1]][j - 1];
            }
        }
    }
}

inline std::pair<long long, long long> solve1(int start, long long limit) {
    int curr = start;
    long long sum = 0, sumA = 0, sumB = 0;
    for (int i = logn; i >= 1 && curr != 0; i--) {
        while (curr && limit >= sum + g[0][curr][i][2]) {
            sum += g[0][curr][i][2];
            sumA += g[0][curr][i][0];
            sumB += g[0][curr][i][1];
            curr = f[0][curr][i];
        }
    }

    if (curr && limit >= sum + g[0][curr][0][0]) {
        sumA += g[0][curr][0][0];
        sum += g[0][curr][0][0];
    }

    return std::make_pair(sumA, sumB);
}

inline int solve2(long long limit) {
    int ans = 0;
    double k = -1;
    for (int i = 1; i <= n; i++) {
        long long tmpA, tmpB;
        std::tie(tmpA, tmpB) = solve1(i, limit);
        double t = 1.0 * tmpA / tmpB;
        if (k == -1 || t < k || (t == k && N[i].h > N[ans].h)) {
            k = t;
            ans = i;
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &N[i].h);

    prepare();

    long long x0;
    scanf("%lld", &x0);
    printf("%d\n", solve2(x0));

    int m;
    scanf("%d", &m);
    while (m--) {
        int s;
        long long x;
        scanf("%d %lld", &s, &x);
        long long sumA, sumB;
        std::tie(sumA, sumB) = solve1(s, x);
        printf("%lld %lld\n", sumA, sumB);
    }

    return 0;
}