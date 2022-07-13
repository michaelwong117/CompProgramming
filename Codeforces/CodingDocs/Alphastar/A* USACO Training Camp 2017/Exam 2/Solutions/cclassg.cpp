#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXT = 7505, INF = 1000000000;

int C, T, L, pos [MAXT], dp [MAXT], pmin [MAXT], smin [MAXT];
pair <int, int> course [MAXT];

int main ()
{
    scanf ("%d %d %d", &C, &T, &L);
    pmin [0] = smin [T] = INF;

    while (C--)
    {
        for (int i = 0; i < T; i++)
            scanf ("%d %d", &course [i].first, &course [i].second);

        sort (course, course + T);

        for (int i = 0, j = 0; i < T; i++)
        {
            while (j < T && pos [j] < course [i].first)
                j++;

            dp [i] = course [i].second + min (course [i].first + pmin [j], smin [j] - course [i].first);
        }

        pmin [0] = INF;

        for (int i = 0; i < T; i++)
            pmin [i + 1] = min (pmin [i], dp [i] - course [i].first);

        smin [T] = INF;

        for (int i = T - 1; i >= 0; i--)
            smin [i] = min (smin [i + 1], dp [i] + course [i].first);

        for (int i = 0; i < T; i++)
            pos [i] = course [i].first;
    }

    printf ("%d\n", pmin [T] + L);

    return 0;
}
