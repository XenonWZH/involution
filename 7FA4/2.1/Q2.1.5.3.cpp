// Q2.1.5.3. 集合划分
// WzhDnwzWzh

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int  n, num[12];
long long ans = 10240000000001LL, x[3] = { 1, 1, 1 };
bool empty[3] = { true, true, true };

void dfs(int step)
{
    if (x[0] + 2 * x[1] + 3 * x[2] >= ans)
        return;
    else if (!empty[0] && !empty[1] && !empty[2] && step >= n)
        ans = x[0] + 2 * x[1] + 3 * x[2];
    if (step >= n)
        return;

    for (int j = 0; j < 3; j++)
    {
        x[j] *= num[step];
        if (x[0] + 2 * x[1] + 3 * x[2] < ans)
        {
            if (!empty[j])
            {
                dfs(step + 1);
            }
            else
            {
                empty[j] = false;
                dfs(step + 1);
                empty[j] = true;
            }
        }
        x[j] /= num[step];
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    dfs(0);

    cout << ans << endl;
    return 0;
}