// Q1.5.4.1. 空间太小了
// WzhDnwzWzh

#include <cstdio>

int main()
{
    FILE *fin, *fout;
    char c;
    int num;
    fin = fopen("pfile.in", "rb");
    fout = fopen("pfile.out", "wb");

    while (true)
    {
        c = fgetc(fin);
        if (c >= '0' && c <= '9')
            break;
    }
    num = c - '0';
    while (true)
    {
        c = fgetc(fin);
        if (!(c >= '0' && c <= '9'))
            break;
        num = num * 10 + c - '0';
    }
    fclose(fin);
    fin = fopen("pfile.in", "rb");
    for (int i = 0; i < num; i++)
        c = fgetc(fin);

    fprintf(fout, "%c\n", c);
    fclose(fin);
    fclose(fout);
    return 0;
}