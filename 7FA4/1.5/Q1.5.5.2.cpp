// Q1.5.5.2. 快速幂
// WzhDnwzWzh

#include <iostream>

using namespace std;

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    cout << binpow(a, b, m) << endl;
    return 0;
}