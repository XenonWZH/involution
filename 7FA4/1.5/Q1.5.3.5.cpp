// Q1.5.3.5. 乒乓球
// WzhDnwzWzh

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    string play;
    int e_hua[5682], e_comp[5682], t_hua[2977], t_comp[2977], e_cnt = 0, t_cnt = 0;
    memset(e_hua, 0, sizeof e_hua);
    memset(e_comp, 0, sizeof e_comp);
    memset(t_hua, 0, sizeof t_hua);
    memset(t_comp, 0, sizeof t_comp);

    while (cin >> play)
        for (int i = 0; i < play.length(); i++)
        {
            if (play[i] == 'W')
            {
                e_hua[e_cnt]++;
                t_hua[t_cnt]++;
            }
            if (play[i] == 'L')
            {
                e_comp[e_cnt]++;
                t_comp[t_cnt]++;
            }
            if (play[i] == 'E')
            {
                for (int j = 0; j <= e_cnt; j++)
                    cout << e_hua[j] << ":" << e_comp[j] << endl;
                cout << endl;
                for (int j = 0; j <= t_cnt; j++)
                    cout << t_hua[j] << ":" << t_comp[j] << endl;
                return 0;
            }
            if ((e_hua[e_cnt] >= 11 || e_comp[e_cnt] >= 11) && abs(e_hua[e_cnt] - e_comp[e_cnt]) >= 2)
                e_cnt++;
            if ((t_hua[t_cnt] >= 21 || t_comp[t_cnt] >= 21) && abs(t_hua[t_cnt] - t_comp[t_cnt]) >= 2)
                t_cnt++;
        }

    return 0;
}