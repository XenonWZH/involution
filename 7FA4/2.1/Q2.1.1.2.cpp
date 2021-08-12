// Q2.1.1.2. 展开函数1
// WzhDnwzWzh

#include <cstdio>
#include <cstdlib>

int n, m, a[311], b[311];

int main()
{
	scanf("%d%d", &n, &m);
	printf("%d\n", n > m ? (m > 0 ? 0 : m) : (n > 0 ? 0 : n));
	printf("%d\n", int((long long)n > (long long)m ? (long long)n : (long long)m));
	for(int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for(int j = 1; j <= m; j++)
		scanf("%d", b + j);
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
        {
            bool fun = false;
	        for(int ii = 1; ii <= m; ii++)
	        	for(int jj = ii + 1; jj <= m; jj++)
	        		for(int kk = jj + 1; kk <= m; kk++)
	        			if(a[i] + a[j] == b[ii] + b[jj] + b[kk])
	        				fun = true;
			if(fun)
				printf("%d %d\n", a[i], a[j]);
        }
	exit(0);
}