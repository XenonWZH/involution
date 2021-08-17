// Q1.5.4.5. 字符串排序
// WzhDnwzWzh

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> str;
    int n;
    string tmp;

    cin >> n;
    getline(cin, tmp);
    for (int i = 0; i < n; i++)
    {
        getline(cin, tmp);
        str.push_back(tmp);
    }

    sort(str.begin(), str.end());

    for (int i = 0; i < n; i++)
        cout << str[i] << '\t';
    cout << endl;
    return 0;
}