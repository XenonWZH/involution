#include <cstdio>
#include <cstring>
#include <queue>

const int MAXN = 60;
const int MAXM = 100;
const int MAXS = 100;
const int MOD = 1e4 + 7;

int trie[MAXN * MAXS + 1][26], tot = 0;
int end[MAXN * MAXS + 1], fail[MAXN * MAXS + 1];
int f[MAXM + 1][MAXN * MAXS + 1];

void insert(char *s) {
    int len = strlen(s), p = 0;
    for (int i = 0; i < len; i++) {
        if (!trie[p][s[i] - 'A']) trie[p][s[i] - 'A'] = ++tot;
        p = trie[p][s[i] - 'A'];
    }
    end[p]++;
}

void build() {
    std::queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (trie[0][i]) {
            q.push(trie[0][i]);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (trie[u][i]) {
                fail[trie[u][i]] = trie[fail[u]][i];
                end[trie[u][i]] += end[trie[fail[u]][i]];
                q.push(trie[u][i]);
            } else trie[u][i] = trie[fail[u]][i];
        }
    }
}

int pow(int a, int b) {
    int ans = 1;
    for (; b; b >>= 1, a = a * a % MOD) if (b & 1) ans = ans * a % MOD;
    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    while (n--) {
        static char s[MAXS + 1];
        scanf("%s", s);
        insert(s);
    }
    build();

    f[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= tot; j++) {
            for (int k = 0; k < 26; k++) {
                if (!end[trie[j][k]]) {
                    f[i + 1][trie[j][k]] = (f[i + 1][trie[j][k]] + f[i][j]) % MOD;
                }
            }
        }
    }

    int ans = pow(26, m);
    for (int i = 0; i <= tot; i++) ans = (ans - f[m][i] + MOD) % MOD;
    printf("%d\n", ans);

    return 0;
}