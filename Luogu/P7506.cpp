#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>

struct Card {
    int base;  // 0 -> 基础牌, 1 -> 解牌, 2 -> 失败
    int type;  // 0 -> 加法（PASS）, 1 -> 减法（TURN）, 2 -> 乘法（DOUBLE）, 3 -> 除法, 4 -> 固定
    int num;

    static Card cardInput() {
        Card card;
        std::string str;
        std::cin >> str;

        if (str[1] >= '0' && str[1] <= '9') {
            card.base = 0;
            if (str[0] == 'A') card.type = 0;
            else if (str[0] == 'B') card.type = 1;
            else if (str[0] == 'C') card.type = 2;
            else if (str[0] == 'D') card.type = 3;
            else if (str[0] == 'E') card.type = 4;

            card.num = 0;
            for (int i = 1, len = str.length(); i < len; i++) card.num = card.num * 10 + (str[i] - '0');
        } else {
            card.base = 1;
            if (str == "PASS") card.type = 0;
            else if (str == "TURN") card.type = 1;
            else if (str == "DOUBLE") card.type = 2;
        }

        return card;
    }

    void cardOutput() {
        if (base == 0) {
            printf("%c%d", 'A' + type, num);
        } else {
            if (type == 0) printf("PASS");
            else if (type == 1) printf("TURN");
            else if (type == 2) printf("DOUBLE");
        }
    }

    int calc(int p) {
        if (base == 1) return p;
        else if (type == 0) return p + num;
        else if (type == 1) return p - num;
        else if (type == 2) return p * num;
        else if (type == 3) return floor(1.0 * p / num);
        else return num;
    }
};

struct Player {
    std::string name;
    std::vector<Card> cards;
    Player *adj[2];

    Card findMax(int p) {
        std::vector<std::vector<Card>::iterator> valid;
        int res = INT_MIN;
        for (int i = 0; i < 3; i++) {
            if (cards[i].base == 0) {
                if (cards[i].calc(p) >= res && cards[i].calc(p) <= 99) {
                    if (cards[i].calc(p) > res) valid.clear();
                    res = cards[i].calc(p);
                    valid.push_back(cards.begin() + i);
                }
            }
        }

        if (valid.empty()) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (cards[j].base == 1 && cards[j].type == i) {
                        Card ret = cards[j];
                        cards.erase(cards.begin() + j);
                        return ret;
                    }
                }
            }
        } else {
            const int order[5] = { 2, 0, 1, 3, 4 };
            for (int i = 0; i < 5; i++) {
                for (int j = 0, len = valid.size(); j < len; j++) {
                    if ((*valid[j]).type == order[i]) {
                        Card ret = *valid[j];
                        cards.erase(valid[j]);
                        return ret;
                    }
                }
            }
        }

        Card ret;
        ret.base = 2;
        return ret;
    }

    Card findMin(int p) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (cards[j].base == 1 && cards[j].type == i) {
                    Card ret = cards[j];
                    cards.erase(cards.begin() + j);
                    return ret;
                }
            }
        }

        std::vector<std::vector<Card>::iterator> valid;
        int res = INT_MAX;
        for (int i = 0; i < 3; i++) {
            if (cards[i].base == 0) {
                if (cards[i].calc(p) <= res && cards[i].calc(p) <= 99) {
                    if (cards[i].calc(p) < res) valid.clear();
                    res = cards[i].calc(p);
                    valid.push_back(cards.begin() + i);
                }
            }
        }

        if (!valid.empty()) {
            const int order[5] = { 3, 1, 0, 2, 4 };
            for (int i = 0; i < 5; i++) {
                for (int j = 0, len = valid.size(); j < len; j++) {
                    if ((*valid[j]).type == order[i]) {
                        Card ret = *valid[j];
                        cards.erase(valid[j]);
                        return ret;
                    }
                }
            }
        }

        Card ret;
        ret.base = 2;
        return ret;
    }
};

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    std::vector<Player> players(n + 1);
    for (int i = 1; i <= n; i++) players[i].cards.resize(3);
    for (int i = 1; i < n; i++) players[i].adj[0] = &players[i + 1];
    for (int i = 2; i <= n; i++) players[i].adj[1] = &players[i - 1];
    players[1].adj[1] = &players[n], players[n].adj[0] = &players[1];

    for (int i = 1; i <= n; i++) {
        std::cin >> players[i].name;
        for (int j = 0; j < 3; j++) players[i].cards[j] = Card::cardInput();
    }

    std::queue<Card> cards;
    for (int i = 0; i < k; i++) cards.push(Card::cardInput());

    Player *onTheGame = &players[1];
    for (int i = 1; i <= m; i++) {
        printf("Round %d:\n", i);

        int p = 0, turn = 0;
        Player *now = onTheGame;
        bool doubled = false;

        while (true) {
            Card card;
            if (doubled) card = now->findMin(p);
            else card = now->findMax(p);

            if (card.base == 2) {
                std::cout << now->name << " lost the game.\n";
                onTheGame = now;
                now->cards.clear();
                for (int i = 0; i < 3; i++) {
                    now->cards.push_back(cards.front());
                    cards.pop();
                }
                break;
            } else {
                p = card.calc(p);
                std::cout << now->name << " used ";
                card.cardOutput();
                std::cout << ",now p=" << p << ".\n";
                now->cards.push_back(cards.front());
                cards.pop();

                if (card.base == 0) {
                    if (doubled) doubled = false;
                    else now = now->adj[turn];
                } else if (card.base == 1) {
                    if (card.type == 1) turn ^= 1;
                    if (card.type == 2) doubled = true;
                    now = now->adj[turn];
                }
            }
        }
    }

    return 0;
}