// E1.5.4.1. 文件输入输出练习
// WzhDnwzWzh

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int a, b;
    freopen("aplusb.in", "r", stdin);
    freopen("aplusb.out", "w", stdout);
    cin >> a >> b;
    cout << a + b << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}