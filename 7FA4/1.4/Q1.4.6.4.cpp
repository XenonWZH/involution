// Q1.4.6.4. 找邻居
// WzhDnwzWzh

#include <cstdio>
#include <set>

const int MAXN = 500000;

int main() {
	int n;
	
	scanf("%d", &n);
	
	static std::set<int> kid;
	
	for (int i = 0, x; i < n; i++) {
		scanf("%d", &x);
		
		auto pos = kid.lower_bound(x);
		
		if (kid.begin() == pos) {
			putchar('0');
		} else {
			pos--;
			printf("%d", *pos);
			pos++;
		}
		putchar(' ');
		if (kid.end() == pos) {
			putchar('0');
		} else printf("%d", *pos);
		puts("");
		
		kid.insert(x);
	}
	
	return 0;
} 