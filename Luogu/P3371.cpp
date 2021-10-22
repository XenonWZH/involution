// P3371 【模板】单源最短路径（弱化版）
// WzhDnwzWzh

#include <iostream>
#include <vector>

std::vector< std::pair<int, int> > graph[1001];

std::vector<int> dijkstra(int n, int m) {
}

int main() {
    int n, m;

    std::cin >> n >> m;
    for (int i = 0, from, to, v; i < m; i++) {
        std::cin >> from >> to >> v;
        graph[from].push_back( std::make_pair(to, v) );
    }

    std::vector<int> ans = dijkstra(n, m);
    for (int each : ans) {
        std::cout << each << " ";
    }

    std::cout << std::endl;
    return 0;
}
