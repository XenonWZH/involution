#include <cstdio>
#include <cstring>

const int MAXD = 10000;

struct Instruction {
    char c[5];
    int r1, c1, r2, c2;
    int a, x[20];
} inst[MAXD];

int r, c, n;

bool solve(int &cellR, int &cellC) {
    for (int i = 0; i < n; i++) {
        if (inst[i].c[0] == 'E') {
            if (inst[i].r1 == cellR && inst[i].c1 == cellC) {
                cellR = inst[i].r2;
                cellC = inst[i].c2;
            } else if (inst[i].r2 == cellR && inst[i].c2 == cellC) {
                cellR = inst[i].r1;
                cellC = inst[i].c1;
            }
        } else {
            int changeR = 0, changeC = 0;

            for (int j = 0; j < inst[i].a; j++) {
                int x = inst[i].x[j];
                if (inst[i].c[0] == 'I') {
                    if (inst[i].c[1] == 'R' && x <= cellR) changeR++;
                    if (inst[i].c[1] == 'C' && x <= cellC) changeC++;
                } else {
                    if (inst[i].c[1] == 'R' && x == cellR) return false;
                    if (inst[i].c[1] == 'C' && x == cellC) return false;

                    if (inst[i].c[1] == 'R' && x < cellR) changeR--;
                    if (inst[i].c[1] == 'C' && x < cellC) changeC--;
                }
            }

            cellR += changeR;
            cellC += changeC;
        }
    }

    return true;
}

int main() {
    int cnt = 1;

    while (scanf("%d %d %d", &r, &c, &n) != EOF) {
        if (r == 0) break;

        for (int i = 0; i < n; i++) {
            scanf("%s", inst[i].c);
            if (inst[i].c[0] == 'E') {
                scanf("%d %d %d %d", &inst[i].r1, &inst[i].c1, &inst[i].r2, &inst[i].c2);
            } else {
                scanf("%d", &inst[i].a);
                for (int j = 0; j < inst[i].a; j++) {
                    scanf("%d", &inst[i].x[j]);
                }
            }
        }
        if (cnt >= 2) putchar('\n');
        printf("Spreadsheet #%d\n", cnt);

        int q;
        scanf("%d", &q);

        for (int i = 0; i < q; i++) {
            int cellR, cellC;
            scanf("%d %d", &cellR, &cellC);
            printf("Cell data in (%d,%d) ", cellR, cellC);

            if (solve(cellR, cellC)) printf("moved to (%d,%d)\n", cellR, cellC);
            else printf("GONE\n");
        }

        cnt++;
    }

    return 0;
}