// Q1.5.3.3. 笨小猴
// WzhDnwzWzh

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int cha[26], minn = 101, maxn = 0, ans;
    string str;
    memset(cha, 0, sizeof(cha));

    cin >> str;

    for (int i = 0; i < str.length(); i++)
        cha[str[i] - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        if (cha[i] != 0)
        {
            if (cha[i] < minn)
                minn = cha[i];
            if (cha[i] > maxn)
                maxn = cha[i];
        }
    }
    ans = maxn - minn;
    for (int i = 2; i * i <= ans; i++)
        if (ans % i == 0)
        {
            cout << "No Answer" << endl << "0" << endl;
            return 0;
        }

    if (ans < 2)
        cout << "No Answer" << endl << "0" << endl;
    else
        cout << "Lucky Word" << endl << ans << endl;
    return 0;
}