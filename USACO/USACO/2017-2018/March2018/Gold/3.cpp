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
 
typedef long long ll; typedef vector<int> vi;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int maxN = 251;
int N, W, mx = 0;
int t[maxN], w[maxN];
vi dp(250001, 1e9);

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("talent.in"); ofstream fout("talent.out");
	fin >> N >> W;
	for(int i = 1; i <= N; i++){
		fin >> w[i] >> t[i];
		mx += t[i];
	}
	dp[0] = 0;
	for(int k = 1; k <= N; k++){
		for(int i = mx; i >= 0; i--){
			if(i-t[k] >= 0) dp[i] = min(dp[i],dp[i-t[k]]+w[k]);
		}
	}
	int res = 0;
	for(int i = 1; i < dp.size(); i++)
		if(dp[i] >= W) res = max(res, (int) (1000.0*i/dp[i]));
	fout << res << endl;
	
}