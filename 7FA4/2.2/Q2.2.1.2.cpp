///max-difference=100
#include <cstdio>

const int N = 3009;

int f[N], arr[N];
bool vis[N];

int dp(int a){
	if(vis[a])
		return f[a];
    vis[a] = true;
	for(int i = a - 1; i >= 0; i--)
		if(arr[i] <= arr[a] && f[a] < dp(i) + 1)
			f[a] = dp(i) + 1;
	return f[a];
}

int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%d", arr + i);
	int a = 0;for(int i=n;i>0;i--)if(a<dp(i))a=dp(i);
	printf("%d\n", a);
	return 0;
}