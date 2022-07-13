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
const int mx = 1500000;

int N, W, dp[mx+1];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("talent.in"); ofstream fout("talent.out");
	fin >> N >> W;
	for(int i = 1; i <= mx; i++) dp[i] = -1e9;
	for(int i = 0; i < N; i++){
		int w, t; fin >> w >> t;
		for(int j = mx; j >= 0; j--){
			if(j-w >= 0) dp[j] = max(dp[j],dp[j-w]+t);
		}
	}
	int res = 0;
	for(int i = W; i <= mx; i++) res = max(res, (int)(dp[i]*1000.0/i));
	fout << res << endl;

	
}