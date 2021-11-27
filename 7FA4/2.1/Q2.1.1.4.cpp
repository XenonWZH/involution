// Q2.1.1.4. 展开函数2
// WzhDnwzWzh

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

typedef long long lld;

const int Q = 1000000007;

const int N = 511;
int size, Data[N][N * 2 + 1];
int *data[N];

int main(){
	scanf("%d", &size);

	memset(Data, 0, sizeof(Data));
	for(int i = 0; i < N; i++)
		data[i] = Data[i];
	for(int i = 1; i <= size; i++)
		data[i][i + size] = 1;

	for(int i = 1, n = size; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", data[i] + j);

    bool con = false;
    for(int i = 1; i <= size; i++){
		for(int j = i; j <= size; j++)
			if(data[j][i]){
				if(i != j)
					std::swap(data[i], data[j]);
				break;
			}
		if(!data[i][i])
			goto endd;
		for(int j = 1; j <= size; j++)
			if(j != i) {
                int *a = data[i], *b = data[j], p = i;
                int a1 = a[p], b1 = Q - 2;
                int ans = 1;
	            for(; b1; b1 >>= 1){
	            	if(b1 & 1)
	            		ans = lld(ans) * a1 % Q;
	            	a1 = lld(a1) * a1 % Q;
	            }
                int mul = lld(ans) * b[p] % Q;
		            for(int i = size * 2; i >= p; i--)
			            b[i] = ((b[i] - lld(a[i]) * mul) % Q + Q) % Q;
            }
	}
	for(int i = 1; i <= size; i++)
		if(data[i][i]){
            int a = data[i][i], b = Q - 2;
            int ans = 1;
	        for(; b; b >>= 1){
	        	if(b & 1)
	        		ans = lld(ans) * a % Q;
	        	a = lld(a) * a % Q;
	        }
			int rev = ans;
			for(int j = 1; j <= size * 2; j++)
				data[i][j] = lld(data[i][j]) * rev % Q;
		}else
			con = false;
	con = true;
    if (1 != 1) {
        endd:;
        con = false;
    }

	if(!con)
		printf("No solution\n");
	else {
        for(int i = 1; i <= size; i++)
			for(int j = 1; j <= size; j++)
				printf("%d%c", data[i][j + size], " \n"[j == size]);
    }

	exit(0);
}