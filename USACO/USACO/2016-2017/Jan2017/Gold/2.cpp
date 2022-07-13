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
#define mpq priority_queue<int>
 
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int mx = 1e5;
int N, K, a[mx], dp[mx][3][21];
vi v = {0,1,2};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("hps.in"); ofstream fout("hps.out");
	fin >> N >> K;
	for(int i = 0; i < N; i++){
		char c; fin >> c;
		if(c == 'P') a[i] = 1;
		if(c == 'S') a[i] = 2;
	}
	dp[0][0][0] = 0 == a[0];
	dp[0][1][0] = 1 == a[0];
	dp[0][2][0] = 2 == a[0];
	for(int i = 1; i < N; i++){
		for(int g = 0; g < 3; g++){
			int c = g == a[i];
			for(int k = 0; k <= K; k++){
				dp[i][g][k] = max(dp[i][g][k],dp[i-1][g][k]);
				for(auto r: v) if(k > 0) dp[i][g][k] = max(dp[i][g][k],dp[i-1][r][k-1]);
				dp[i][g][k] += c;
			} 
		}
	}
	int res = 0;
	for(int i = 0; i <= K; i++){
		for(int g = 0; g < 3; g++) res = max(res,dp[N-1][g][i]);
	}
	fout << res << endl;
	
}