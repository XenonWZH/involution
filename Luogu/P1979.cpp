#include <cstdio>
#include <climits>
#include <iostream>
#include <queue>

const int MAXN = 30;
const int dx[4] = { 1, 0, 0, -1 };
const int dy[4] = { 0, 1, -1, 0 };

int n, m;

struct Map {
    bool exist;
    int f[4][4];
    int dis;
    struct Node {
        int dis;
        bool vis;
    } N[4];
} maps[MAXN + 1][MAXN + 1];

struct Coor {
    int i, j;

    Coor() {}
    Coor(int i, int j) : i(i), j(j) {}

    Coor move(int dir) {
        return Coor(i + dx[dir], j + dy[dir]);
    }

    Map &map() {
        return maps[i][j];
    }

    bool exist() {
        return i > 0 && j > 0 && i <= n && j <= m;
    }

    bool operator==(const Coor &other) const {
        return i == other.i && j == other.j;
    }
};

struct Point {
    Coor c;
    int d;

    Point(Coor c, int d) : c(c), d(d) {}
};

inline int bfs(Coor s, Coor t, Coor c) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            maps[i][j].dis = INT_MAX;
        }
    }

    std::queue<Coor> q;
    s.map().dis = 0;
    q.push(s);

    while (!q.empty()) {
        Coor v = q.front();
        q.pop();

        if (v == t) return v.map().dis;

        for (int i = 0; i < 4; i++) {
            Coor u = v.move(i);

            if (!u.exist() || !u.map().exist || u == c) continue;

            if (u.map().dis > v.map().dis + 1) {
                u.map().dis = v.map().dis + 1;
                q.push(u);
            }
        }
    }

    return INT_MAX;
}

inline void prepare() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!maps[i][j].exist) continue;

            Coor v(i, j);
            for (int s = 0; s < 4; s++) {
                Coor ps = v.move(s);

                for (int t = s + 1; t < 4; t++) {
                    Coor pt = v.move(t);

                    if (!ps.exist() || !ps.map().exist || !pt.exist() || !pt.map().exist) v.map().f[s][t] = v.map().f[t][s] = INT_MAX;
                    else v.map().f[s][t] = v.map().f[t][s] = bfs(ps, pt, v);
                }
            }
        }
    }
}

inline int spfa(Point s, Coor t) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                maps[i][j].N[k].dis = INT_MAX;
                maps[i][j].N[k].vis = false;
            }
        }
    }

    std::queue<Point> q;
    q.push(s);
    s.c.map().N[s.d].dis = 0;

    while (!q.empty()) {
        Point point = q.front();
        q.pop();

        Coor &v = point.c;
        int &d = point.d;

        v.map().N[d].vis = false;

        for (int i = 0; i < 4; i++) {
            if (i == d || v.map().f[d][i] == INT_MAX) continue;

            if (v.map().N[i].dis > v.map().N[d].dis + v.map().f[d][i]) {
                v.map().N[i].dis = v.map().N[d].dis + v.map().f[d][i];
                if (!v.map().N[i].vis) {
                    v.map().N[i].vis = true;
                    q.push(Point(v, i));
                }
            }
        }

        if (v.map().N[d].dis != INT_MAX) {
            Coor u = v.move(d);
            int t = 3 - d;
            if (u.map().N[t].dis > v.map().N[d].dis + 1) {
                u.map().N[t].dis = v.map().N[d].dis + 1;
                if (!u.map().N[t].vis) {
                    u.map().N[t].vis = true;
                    q.push(Point(u, t));
                }
            }
        }
    }

    int res = INT_MAX;
    for (int i = 0; i < 4; i++) {
        res = std::min(res, t.map().N[i].dis);
    }

    return res;
}

int main() {
    int q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            scanf("%d", &x);
            maps[i][j].exist = x;
        }
    }

    prepare();

    while (q--) {
        Coor e, s, t;
        scanf("%d %d %d %d %d %d", &e.i, &e.j, &s.i, &s.j, &t.i, &t.j);

        if (s == t) {
            puts("0");
            continue;
        }

        int ans = INT_MAX;
        for (int i = 0; i < 4; i++) {
            Coor v = s.move(i);
            if (!v.exist()) continue;

            int d1 = bfs(e, v, s);
            if (d1 == INT_MAX) continue;

            int d2 = spfa(Point(s, i), t);
            if (d2 == INT_MAX) continue;

            ans = std::min(ans, d1 + d2);
        }

        printf("%d\n", ans == INT_MAX ? -1 : ans);
    }

    return 0;
}