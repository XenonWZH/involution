#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

void solve() {
    std::string s;

    std::cin >> s;

    int len = s.length();

    std::vector<char> ss;
    std::vector<char> v;
    for (int i = 0; i < len; i++) {
        while (!ss.empty() && ss.back() > s[i]) {
            v.push_back(std::min(ss.back() + 1, (int)'9'));
            ss.pop_back();
        }
        ss.push_back(s[i]);
    }
    std::sort(v.begin(), v.end());
    std::vector<char> ans;
    std::merge(ss.begin(), ss.end(), v.begin(), v.end(), std::back_inserter(ans));
    for (char ch : ans) putchar(ch);
    putchar('\n');
}

int main() {
    int t;

    scanf("%d", &t);

    while (t--) solve();

    return 0;
}