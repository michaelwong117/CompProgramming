#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;

const int MAX = 305;

int N, M, R, total;
int rating [MAX][MAX];
int ratsum [MAX], parsum [MAX], temp [MAX];

inline void merge (int left, int mid, int right)
{
    int pos1 = left, pos2 = mid, count = 0;

    while (pos1 < mid && pos2 < right)
    {
	if (parsum [pos1] < parsum [pos2])
	    temp [count++] = parsum [pos1++];
	else
	    temp [count++] = parsum [pos2++];
    }

    if (pos1 < mid)
    {
	do
	    temp [count++] = parsum [pos1++];
	while (pos1 < mid);
    }
    else
    {
	do
	    temp [count++] = parsum [pos2++];
	while (pos2 < right);
    }

    memcpy (parsum + left, temp, (right - left) * sizeof (int));
}

void solve (int left, int right)
{
    if (left + 1 >= right)
	return;

    int mid = (left + right) >> 1;

    solve (left, mid);
    solve (mid, right);

    for (int pos1 = left, pos2 = mid; pos1 < mid; pos1++)
    {
	while (pos2 < right && parsum [pos2] - parsum [pos1] < R)
	    pos2++;

	total += right - pos2;
    }

    merge (left, mid, right);
}

int main ()
{
    scanf ("%d %d %d", &N, &M, &R);

    for (int i = 0; i < N; i++)
	for (int j = 0; j < M; j++)
	    scanf ("%d", &rating [i][j]);

    for (int i = 0; i < N; i++)
    {
	memset (ratsum, 0, sizeof (ratsum));

	for (int j = i; j < N; j++)
	{
	    parsum [0] = 0;

	    for (int k = 0; k < M; k++)
	    {
		ratsum [k] += rating [j][k];
		parsum [k + 1] = parsum [k] + ratsum [k];
	    }

	    solve (0, M + 1);
	}
    }

    printf ("%d\n", total);
}
