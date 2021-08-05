// A. Polycarp and Coins
// WzhDnwzWzh

#include <iostream>

using namespace std;

int main()
{
    int t, n, c1, c2;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;

        c1 = c2 = n / 3;
        n %= 3;
        if (n == 1)
            c1++;
        if (n == 2)
            c2++;

        cout << c1 << " " << c2 << endl;
    }

    return 0;
}