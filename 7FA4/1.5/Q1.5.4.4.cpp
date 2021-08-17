// Q1.5.4.4. IO方式转换2
// WzhDnwzWzh

#include <iostream>
#include <iomanip>

using namespace std;

int a;
long long b;
double c;
char d;
string e;

int main()
{
    cin >> a >> b >> c >> d >> e;
    cout << "a: " << a << endl << "b: " << b << " c: " << std::fixed << std::setprecision(3) << c << endl << endl << "  d:" << d << "," << endl << "e:" << e;
    return 0;
}