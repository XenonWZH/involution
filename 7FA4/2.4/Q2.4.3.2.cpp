#include <cstdio>
#include <cstring>
#include <set>

const int MAXN = 300000;

int main() {
    int n, k = 0, top = 0;
    static std::pair<int, int> x[MAXN];

    scanf("%d", &n);

    static std::set< std::pair<int, int>, std::greater< std::pair<int, int> > > mx;
    static int visited[MAXN];
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int in;
            scanf("%d", &in);
            x[k++] = std::make_pair(in, top);
            mx.insert( std::make_pair(in, top++) );
            std::pair<int, int> kick;
            for (auto each : mx) {
                if (visited[each.second]) continue;
                kick = each;
                break;
            }
            printf("%d\n", kick.first);
        } else {
            std::pair<int, int> kick;
            for (auto each : mx) {
                if (visited[each.second]) continue;
                kick = each;
                break;
            }
            std::swap(x[kick.first % k], x[k - 1]);
            visited[x[k - 1].second] = true;
            printf("%d\n", x[k - 1].first);
            k--;
        }
    }

    return 0;
}