//g++ filename.cpp -std=c++14 -DH
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define endl '\n'
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>>
#define heap priority_queue<int>

typedef long long ll; typedef vector<int> vi;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int maxN = 101;
//dp[cur pos in array i][last breakout l][number of breakouts b]
int a[maxN], dp[maxN][maxN][maxN], mindif = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("taming.in"); ofstream fout("taming.out");
	int N; fin >> N;
	for(int i = 1; i <= N; i++){
		fin >> a[i];
	}
	for(int i = 1; i <= N; i++){
		for(int l = 1; l <= N; l++){
			for(int b = 1; b <= N; b++) dp[i][l][b] = 101;
		}
	}
	if(a[1] != 0) mindif++;
	dp[1][1][1] = mindif;
	for(int i = 1; i <= N; i++){
		for(int l = 1; l <= N; l++){
			for(int b = 1; b <= N; b++){
				int out = 0, cont = 0;
				//breaking out on i
				if(a[i+1] != 0) out = 1;
				//staying continuous
				if(a[i+1] != i+1-l || a[i+1] == 0) cont = 1;
				dp[i+1][l][b] = min(dp[i+1][l][b],dp[i][l][b]+cont);
				dp[i+1][i+1][b+1] = min(dp[i+1][i+1][b+1],dp[i][l][b]+out);
			}
		}
	}
	for(int i = 1; i <= N; i++){
		int res = 101;
		for(int l = 1; l <= N; l++) res = min(res,dp[N][l][i]);
		fout << res << endl;

	}


}
