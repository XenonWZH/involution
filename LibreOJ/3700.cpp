#include <cstdio>
#include <iostream>
#include <string>
#include <tuple>
#include <map>
#include <vector>

std::map<std::string, std::string> def;
std::map<std::string, bool> vis;

inline bool isID(char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '_') return true;
    else return false;
}

inline std::tuple<std::string, bool, int> reads(std::string src, int pos) {
    if (isID(src[pos])) {
        std::string str = "";
        int len = src.length();
        while (pos < len && isID(src[pos])) {
            str += src.substr(pos, 1);
            pos++;
        }
        return std::make_tuple(str, true, pos);
    } else {
        std::string str = "";
        str += src.substr(pos, 1);
        return std::make_tuple(str, false, pos + 1);
    }
}

inline std::pair<std::string, int> readDef(std::string src, int pos) {
    int len = src.length();
    while (pos < len && isspace(src[pos])) pos++;
    std::string str = "";
    while (pos < len && !isspace(src[pos])) str += src[pos++];
    return std::make_pair(str, pos);
}

void solve(std::string str) {
    if (def.count(str) != 0 && !vis[str]) {
        vis[str] = true;
        std::string src = str;
        str = def[str];
        std::tuple<std::string, bool, int> getReads = std::make_tuple("", true, 0);
        int len = str.length();
        std::vector<std::string> vec;
        while (std::get<2>(getReads) < len) {
            getReads = reads(str, std::get<2>(getReads));
            vec.push_back(std::get<0>(getReads));
        }
        for (std::string each : vec) solve(each);
        vis[src] = false;
    } else std::cout << str;
}

int main() {
    std::cin.tie(0);
    std::cout.tie(0);

#ifndef XEDEBUG
    freopen("preprocessor.in", "r", stdin);
    freopen("preprocessor.out", "w", stdout);
#endif

    int n;

    std::cin >> n;
    std::cin.ignore();

    for (int i = 1; i <= n; i++) {
        std::string str;
        std::getline(std::cin, str);
        std::tuple<std::string, bool, int> getReads = std::make_tuple("", true, 0);
        int len = str.length();

        while (std::get<2>(getReads) < len) {
            getReads = reads(str, std::get<2>(getReads));

            if (std::get<1>(getReads)) {
                vis.clear();
                for (auto each : def) vis[each.first] = false;
                solve(std::get<0>(getReads));
            } else if (std::get<0>(getReads) == "#") {
                getReads = reads(str, std::get<2>(getReads));
                if (std::get<0>(getReads) == "define") {
                    std::pair<std::string, int> from = readDef(str, std::get<2>(getReads));
                    std::string to = str.substr(from.second + 1);
                    def[from.first] = to;
                    getReads = std::make_tuple(to, true, len);
                } else if (std::get<0>(getReads) == "undef") {
                    std::string from = str.substr(std::get<2>(getReads) + 1);
                    def.erase(from);
                    getReads = std::make_tuple(from, true, len);
                } else {
                    std::cout << "#";
                    getReads = std::make_tuple("#", false, std::get<2>(getReads) + 1);
                }
            } else std::cout << std::get<0>(getReads);
        }

        std::cout << "\n";
    }

#ifndef XEDEBUG
    fclose(stdin);
    fclose(stdout);
#endif

    return 0;
}