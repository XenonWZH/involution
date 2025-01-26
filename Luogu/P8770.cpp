#include<iostream>
using namespace std;
int main() {
    string ans [] = {
        "443", // 双引号中替换为 A 题的答案
        "LLLV", // 双引号中替换为 B 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}