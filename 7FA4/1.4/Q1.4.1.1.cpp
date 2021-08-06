// Q1.4.1.1. 最大乘积2
// WzhDnwzWzh

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    switch (n % 3)
    {
    case 0:
        for (int i = 0; i < n / 3; i++)
            cout << "3 ";
        cout << endl;
        break;
    case 1:
        cout << "2 2 ";
        for (int i = 0; i < (n - 4) / 3; i++)
            cout << "3 ";
        cout << endl;
        break;
    case 2:
        cout << "2 ";
        for (int i = 0; i < (n - 1) / 3; i++)
            cout << "3 ";
        cout << endl;
        break;
    default:
        break;
    }

    return 0;
}