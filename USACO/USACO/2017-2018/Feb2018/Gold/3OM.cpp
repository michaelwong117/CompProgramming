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
const int maxN = 101, INF = 101;
//dp[cur pos in array i][last breakout l][number of breakouts b in first i entries]
int N, a[maxN], dp[maxN][maxN][maxN], mindif = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("taming.in"); ofstream fout("taming.out");
	fin >> N;
	for(int i = 0; i < N; i++) fin >> a[i];
	for(int i = 0; i < N; i++)
		for(int l = 0; l <= i; l++)
			for(int b = 0; b <= N; b++)
				dp[i][l][b] = INF;
	dp[0][0][1] = a[0]!=0;
	for(int i = 1; i < N; i++){
		for(int l = 0; l <= i; l++)
			for(int b = 1; b <= i+1; b++){
				if(l < i) dp[i][l][b] = dp[i-1][l][b];
				else{
					for(int l1 = 0; l1 < i; l1++) 
						dp[i][l][b] = min(dp[i][l][b], dp[i-1][l1][b-1]);
				}
				dp[i][l][b] += a[i]!=i-l;
			}
	}
	for(int b=1;b<=N;b++){
		int res = INF;
		for(int l=0;l<N;l++) res = min(res, dp[N-1][l][b]);
		fout << res << endl;
	}


}