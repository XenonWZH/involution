// Q1.3.1.3. 谁拿了最多的奖学金（整数版）
// WzhDnwzWzh

#include <iostream>

using namespace std;

int main()
{
    int name, job, south, ans_name, n, score, classes, artical, money, maxn = 0, sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        money = 0;
        cin >> name >> score >> classes >> job >> south >> artical;

        if (score > 80 && artical >= 1)
            money += 8000;
        if (score > 85 && classes > 80)
            money += 4000;
        if (score > 90)
            money += 2000;
        if (score > 85 && south == 1)
            money += 1000;
        if (classes > 80 && job == 1)
            money += 850;
        sum += money;
        if (money > maxn)
        {
            maxn = money;
            ans_name = name;
        }
    }

    cout << ans_name << endl << maxn << endl << sum << endl;
    return 0;
}