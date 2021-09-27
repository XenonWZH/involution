///max-difference=35
#include <cstdio>
int n, a[2001];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n - 1; ++i){
		for(int j = i; j <= n; ++j)
			if(a[i] > a[j]) {
				a[i] += a[j];
				a[j] = a[i] - a[j];
                a[i] -= a[j];
			}
	}
	for(int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
}