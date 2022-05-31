#include <cstring>
#include <iostream>
#include <vector>

const int MAXN = 255;

int main() {
    std::string str;
    std::vector<std::string> vec;
    bool vis[MAXN];

    while (std::cin >> str) vec.push_back(str);

    std::vector<std::string> vecNot;
    bool isNot = false;
    for (int i = 0, size = vec.size(); i < size; i++) {
        if (vec[i] == "not") {
            if (vec[i + 1] == "and" || vec[i + 1] == "or") {
                std::cout << "error" << std::endl;
                return 0;
            } else isNot = !isNot;
        } else {
            if (isNot) {
                if (vec[i] == "true") vecNot.push_back("false");
                if (vec[i] == "false") vecNot.push_back("true");
                isNot = false;
            } else vecNot.push_back(vec[i]);
        }
    }

    std::vector<std::string> vecAnd;
    memset(vis, false, sizeof(vis));

    for (int i = 0, size = vecNot.size(); i < size; i++) {
        if (vecNot[i] == "and") {
            if (i == 0 || i == size - 1 || (vecNot[i - 1] != "true" && vecNot[i - 1] != "false") || (vecNot[i + 1] != "true" && vecNot[i + 1] != "false")) {
                std::cout << "error" << std::endl;
                return 0;
            } else {
                if (vis[i - 1]) {
                    vecNot[i - 1] = vecAnd.back();
                    vecAnd.pop_back();
                }
                if (vecNot[i - 1] == "true" && vecNot[i + 1] == "true") vecAnd.push_back("true");
                else vecAnd.push_back("false");
                vis[i + 1] = true;
                i++;
            }
        } else if (i == size - 1 || vecNot[i + 1] != "and") vecAnd.push_back(vecNot[i]);
    }

    std::vector<std::string> vecOr;
    memset(vis, false, sizeof(vis));

    for (int i = 0, size = vecAnd.size(); i < size; i++) {
        if (vecAnd[i] == "or") {
            if (i == 0 || i == size - 1 || (vecAnd[i - 1] != "true" && vecAnd[i - 1] != "false") || (vecAnd[i + 1] != "true" && vecAnd[i + 1] != "false")) {
                std::cout << "error" << std::endl;
                return 0;
            } else {
                if (vis[i - 1]) {
                    vecAnd[i - 1] = vecOr.back();
                    vecOr.pop_back();
                }
                if (vecAnd[i - 1] == "false" && vecAnd[i + 1] == "false") vecOr.push_back("false");
                else vecOr.push_back("true");
                vis[i + 1] = true;
                i++;
            }
        } else if (i == size - 1 || vecAnd[i + 1] != "or") vecOr.push_back(vecAnd[i]);
    }

    if (vecOr.size() != 1) std::cout << "error" << std::endl;
    else std::cout << vecOr[0] << std::endl;

    return 0;
}