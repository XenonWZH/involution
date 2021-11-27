// Q2.1.1.5. 展开函数3
// WzhDnwzWzh

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

const int N = 100011;
const double eps = 1e-8;
int n;

struct Point{
	double x, y;
}points[N], pnan = (Point){NAN, NAN}, zero = (Point){0, 0};

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		static char buff[111];
		std::string op;
		scanf("%s", buff);
		op = buff;
		if(op == "point"){
			double x, y;
			scanf("%lf%lf", &x, &y);
			points[i] = (Point){x, y};
		}else if(op == "move"){
			int x, y;
			scanf("%d%d", &x, &y);
            points[i] = (Point){points[x].x + points[y].x, points[x].y + points[y].y};
			printf("%.10f %.10f\n", points[i].x, points[i].y);
		}else if(op == "area"){
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			printf("%.10f\n", ((Point){points[y].x - points[x].x, points[y].y - points[x].y}.x * (Point){points[z].x - points[x].x, points[z].y - points[x].y}.y - (Point){points[y].x - points[x].x, points[y].y - points[x].y}.y * (Point){points[z].x - points[x].x, points[z].y - points[x].y}.x) * .5);
		}else{
			printf("Error op = %s\n", buff);
		}
	}
	exit(0);
}