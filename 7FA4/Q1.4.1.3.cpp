// Q1.4.1.3. 最大乘积
// WzhDnwzWzh

#include <iostream>
using namespace std;

int main()
{
    int n, ans, more;
    cin >> n;

    for (ans = 2; (ans + 2) * (ans - 1) / 2 < n; ans++);
    more = (ans + 2) * (ans - 1) / 2 - n;

    if (n <= 4)
        cout << n;
    else for (int i = 2; i <= ans; i++)
        if (i != more)
            cout << i << " ";
    cout << endl;
    return 0;
}