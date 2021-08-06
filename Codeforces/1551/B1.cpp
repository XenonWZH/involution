// B1. Wonderful Coloring - 1
// WzhDnwzWzh

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int t, bowl[26], ans;
    bool green[26];
    string str;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ans = 0;
        memset(green, false, sizeof(green));
        memset(bowl, 0, sizeof(bowl));
        cin >> str;

        for (int i = 0; i < str.length(); i++)
            bowl[str[i] - 'a']++;
        sort(bowl, bowl + 26, greater<int>());
        for (int j = 0; bowl[j] > 0 && j < 26; j++)
        {
            if (bowl[j] >= 2)
                ans++;
            if (bowl[j] == 1 && !green[j])
            {
                if (j == 25 || bowl[j + 1] == 0)
                    break;
                green[j + 1] = true;
                ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}