// Q1.5.3.2. 潜伏者
// WzhDnwzWzh

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    char mark[26];
    string holded, sources, tran;
    bool failed[26];
    memset(mark, '-', sizeof(mark));
    memset(failed, false, sizeof(failed));

    cin >> sources >> holded >> tran;

    if (holded.length() != sources.length())
    {
        cout << "Failed" << endl;
        return 0;
    }
    for (int i = 0; i < sources.length(); i++)
    {
        if (mark[sources[i] - 'A'] != '-' && mark[sources[i] - 'A'] != holded[i])
        {
            cout << "Failed" << endl;
            return 0;
        }
        else
            mark[sources[i] - 'A'] = holded[i];
    }

    for (int i = 0; i < 26; i++)
    {
        if (mark[i] == '-' || failed[mark[i] - 'A'])
        {
            cout << "Failed" << endl;
            return 0;
        }
        failed[mark[i] - 'A'] = true;
    }
    for (int i = 0; i < tran.length(); i++)
        cout << mark[tran[i] - 'A'];
    cout << endl;
    return 0;
}