// E1.4.2.3. 最大数
// WzhDnwzWzh

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool comp(string a, string b)
{
    return a + b > b + a;
}

int main()
{
    string str[1000];
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> str[i];

    sort(str, str + n, comp);

    for (int i = 0; i < n; i++)
        cout << str[i];
    cout << endl;
    return 0;
}