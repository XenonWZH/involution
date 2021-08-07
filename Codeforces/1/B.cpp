// B. Spreadsheets
// WzhDnwzWzh

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_RXCY(string str)
{
    if (str[0] == 'R' && str[1] >= '0' && str[1] <= '9')
    {
        for (int i = 2; i < str.length() - 1; i++)
            if (str[i] == 'C')
                return true;
        return false;
    }
    else
        return false;
}

vector<int> get_pos(bool RXCY, string str)
{
    int x = 0, y = 0, i;
    vector<int> ans;

    if (RXCY)
    {
        for (i = 1; str[i] != 'C'; i++)
            x = x * 10 + str[i] - '0';
        for (i++; i < str.length(); i++)
            y = y * 10 + str[i] - '0';
    }
    else
    {
        for (i = 0; !(str[i] >= '0' && str[i] <= '9'); i++)
            y = y * 26 + str[i] - 'A' + 1;
        for (; i < str.length(); i++)
            x = x * 10 + str[i] - '0';
    }

    ans.push_back(x);
    ans.push_back(y);
    return ans;
}

string pos_to_string(bool to_RXCY, vector<int> pos)
{
    string ans = "";
    int x;

    if (to_RXCY)
        ans = "R" + to_string(pos[0]) + "C" + to_string(pos[1]);
    else
    {
        x = pos[1];
        while (x > 0)
        {
            x -= 1;
            ans = (char)(x % 26 + 'A') + ans;
            x /= 26;
        }
        ans += to_string(pos[0]);
    }

    return ans;
}

int main()
{
    int n;
    string str;
    vector<int> pos;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;

        pos = get_pos(is_RXCY(str), str);

        cout << pos_to_string(!is_RXCY(str), pos) << endl;
    }

    return 0;
}