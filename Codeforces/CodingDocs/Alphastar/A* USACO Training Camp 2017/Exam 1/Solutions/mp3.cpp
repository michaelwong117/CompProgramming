// solution written by Peter Fulla
#include <cstdio>
#include <algorithm>
#include <vector>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FORD(i, a, b) for(int i = (int)(a); i >= (int)(b); --i)
using namespace std;

struct Function{
	int a, b, c;
};

int N, V, R, N2;
vector<char> Z;
vector<int> T, P;
vector<Function> F;

bool cmp(const int a, const int b){
	return T[a] < T[b];
}

int main(){
	scanf("%d %d %d ", &N, &V, &R);
	Z.resize(N);
	T.resize(N);
	REP(i, N)
		scanf("%c %d ", &Z[i], &T[i]);

	FORD(i, N - 1, 1)
		T[i] -= T[i - 1];

	P.resize(N - 1);
	REP(i, N - 1)
		P[i] = i + 1;

	sort(P.begin(), P.end(), cmp);

	N2 = 1;
	while(N2 < N)
		N2 *= 2;

	F.resize(2 * N2, (Function){0, V, 0});


	int resT = -1, resS = R;

	REP(i, N - 1){
		int j = N2 + P[i];

		if(Z[P[i]] == '+')
			F[j] = (Function){0, V - 1, 1};
		else
			F[j] = (Function){1, V, -1};

		while(j > 1){
			j /= 2;

			F[j].a = max(F[2 * j].a, F[2 * j + 1].a - F[2 * j].c);
			F[j].b = min(F[2 * j].b, F[2 * j + 1].b - F[2 * j].c);

			if(F[j].a <= F[j].b)
				F[j].c = F[2 * j].c + F[2 * j + 1].c;
			else if(F[2 * j].a > F[2 * j + 1].b - F[2 * j].c)
				F[j] = (Function){F[2 * j + 1].b, F[2 * j + 1].b, F[2 * j + 1].c};
			else
				F[j] = (Function){F[2 * j + 1].a, F[2 * j + 1].a, F[2 * j + 1].c};
		}

		if(i == N - 2 || T[P[i]] != T[P[i + 1]]){
			if(F[1].a + F[1].c <= R && R < F[1].b + F[1].c){
				resT = i;
				resS = R - F[1].c;
			}else if(R == F[1].b + F[1].c){
				resT = i;
				resS = V;
			}
		}
	}

	if(resT == N - 2)
		printf("infinity\n");
	else
		printf("%d %d\n", T[P[resT + 1]] - 1, resS);
}
