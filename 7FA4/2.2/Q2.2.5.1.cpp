// Q2.2.5.1. 背包问题：不超过的01背包（DEBUG）
// WzhDnwzWzh

///max-difference=80
#include <cstdio>

const int MAX_N = 110;
const int MAX_M = 10011;
const int INF = 1000;
int v[MAX_N], m[MAX_N], f[MAX_N][MAX_M];

//f(i,j)表示前j个物品，总重量为i，获得的最大价值
int main() {
	int n, M;
	scanf("%d%d", &n, &M);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &m[i], &v[i]);
	}

	for(int i = 0; i <= n; i++)
		f[i][0] = -INF;
	f[0][0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= M; j++){
			f[i][j] = f[i - 1][j];
			if(j >= m[i] && f[i][j] < f[i - 1][j - m[i]] + v[i])
				f[i][j] = f[i - 1][j - m[i]] + v[i];
		}

	printf("%d\n", f[n][M]);
	return 0;
}