// 673 - Parentheses Balance
// WzhDnwzWzh

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int n;
    string str;
    stack<char> op;
    bool balance;

    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        balance = true;
        getline(cin, str);

        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == '(' || str[j] == '[')
                op.push(str[j]);
            if (str[j] == ')')
            {
                if (!op.empty() && op.top() == '(')
                    op.pop();
                else
                {
                    balance = false;
                    break;
                }
            }
            if (str[j] == ']')
            {
                if (!op.empty() && op.top() == '[')
                    op.pop();
                else
                {
                    balance = false;
                    break;
                }
            }
        }

        if (balance && op.empty())
            printf("Yes\n");
        else
            printf("No\n");
        while (!op.empty())
            op.pop();
    }
}