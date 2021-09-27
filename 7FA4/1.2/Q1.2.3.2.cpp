///max-difference=35
#include <cstdio>
int n, a[2001];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i){
		int j = i;
		while(a[j] < a[j - 1] && j > 0){
			int t = a[j];
			a[j] = a[j - 1];
			a[j - 1] = t;
			j--;
		}
	}
	for(int i = 0; i < n; ++i)
		printf("%d ", a[i]);
}