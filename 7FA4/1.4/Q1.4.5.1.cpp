// Q1.4.5.1. 基数排序（简化版1）
// WzhDnwzWzh

#include <cstdio>

struct st
{
    unsigned long long num;
    int score;
} student[1000000];

bool comp(st a, st b)
{
    if (a.score == b.score)
        return a.num < b.num;
    return a.score > b.score;
}

void qs(st s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r;
        st x = s[l];
        while (i < j)
        {
            while(i < j && !comp(s[j], x))
                j--;  
            if(i < j) 
                s[i++] = s[j];
            
            while(i < j && comp(s[i], x))
                i++;  
            if(i < j) 
                s[j--] = s[i];
        }
        s[i] = x;
        qs(s, l, i - 1);
        qs(s, i + 1, r);
    }
}

int main()
{
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%llu%d", &student[i].num, &student[i].score);

    qs(student, 0, n);

    for (int i = 0; i < n; i++)
        printf("%llu %d\n", student[i].num, student[i].score);
    return 0;
}