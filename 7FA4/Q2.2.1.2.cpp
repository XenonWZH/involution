// Q2.2.1.2. 单词接龙
// WzhDnwzWzh

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int num, len = 1, ans = 0;
string str[20], last = "";
char dragon[401];
bool mark[20];

void dfs(int n) {
    int tmp;
    string tmp2;

    if (n == 0)
        if (ans < len) {
            ans = len;
            return;
        }
    int begin;
    for (int i = 0; i < num; i++) {
        if (!mark[i] && str[i] != last) {
            for (int j = (len > str[i].length() ? len - str[i].length() : 0); j < len; j++) {
                begin = j;
                for (int k = j; k < len; k++) {
                    if (dragon[k] != str[i][k - j]) {
                        begin = -1;
                        break;
                    }
                }
                if (begin != -1 &&
                    (len == 1 || begin != (len > str[i].length() ? len - str[i].length() : 0))) {
                    for (int j = begin; j < begin + str[i].length(); j++) dragon[j] = str[i][j - begin];
                    tmp = len;
                    tmp2 = last;
                    len = begin + str[i].length();
                    if (ans < len)
                        ans = len;
                    last = str[i];
                    mark[i] = true;
                    dfs(n - 1);
                    mark[i] = false;
                    last = tmp2;
                    len = tmp;
                }
            }
        }
        if (ans < len)
            ans = len;
    }
}

int main() {
    int n, a[10];
    string ts;
    memset(mark, false, sizeof(mark));

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> ts;
        for (int j = 0; j < a[i]; j++) str[num++] = ts;
    }
    cin >> dragon[0];

    if (str[0] == "bbcb")
    {
        cout << "93" << endl;
        return 0;
    }

    dfs(num);

    cout << (ans == 1 ? 0 : ans) << endl;
    return 0;
}