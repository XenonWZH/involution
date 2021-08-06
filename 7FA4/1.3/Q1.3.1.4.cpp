// Q1.3.1.4. 整数对数
// WzhDnwzWzh

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long double a, s;
    int i;

    cin >> a >> s;

    for (i = 0; pow(a, i) <= s; i++);
    i--;

    cout << i << endl;
    return 0;
}