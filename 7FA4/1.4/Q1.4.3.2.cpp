// Q1.4.3.2. 珍珠项链
// WzhDnwzWzh

#include <iostream>

using namespace std;

int main()
{
    long long n, w[400001], sum;
    bool is_ans;

    cin >> n;
    cin >> w[1];
    w[1]--;
    w[n + 1] = w[1];
    for (int i = 2; i <= n; i++)
    {
        cin >> w[i];
        w[i]--;
        w[n + i] = w[i];
    }

    for (int i = 1; i <= n; i++)
    {
        is_ans = true;
        sum = 0;
        for (int j = i; j <= i + n; j++)
        {
            sum += w[j];
            if (sum >= 0)
            {
                is_ans = false;
                break;
            }
        }

        if (is_ans)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
    return 0;
}