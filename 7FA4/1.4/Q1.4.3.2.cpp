// Q1.4.3.2. 珍珠项链
// WzhDnwzWzh

#include <iostream>

using namespace std;

int main()
{
    long long n, w, minn = 1e10, pos = -1;

    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        cin >> w;
        if (w < minn)
        {
            minn = w;
            pos = i + 1;
        }
    }

    cout << pos << endl;
    return 0;
}