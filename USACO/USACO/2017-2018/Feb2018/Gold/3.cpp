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
const int mx = 100;
int n, a[mx], dp[mx][mx][mx+1];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("taming.in"); ofstream fout("taming.out");
	fin >> n;
	for(int i = 0; i < n; i++) fin >> a[i];
	for(int i = 0; i < n; i++){
		for(int l = 0; l <= i; l++){
			for(int b = 0; b <= n; b++){
				dp[i][l][b] = 1e9;
			}
		}
	}
	if(a[0] != 0) dp[0][0][1] = 1;
	else dp[0][0][1] = 0;
	for(int i = 1; i < n; i++){
		for(int l = 0; l < i; l++){
			for(int b = 1; b <= n; b++){
				int cont = 0, out = 0;
				if(a[i] != i-l) cont = 1;
				if(a[i] != 0) out = 1;
				dp[i][l][b] = min(dp[i][l][b],dp[i-1][l][b]+cont);
				dp[i][i][b] = min(dp[i][i][b],dp[i-1][l][b-1]+out);
			}
		}
	}
	for(int b = 1; b <= n; b++){
		int mn = 1e9;
		for(int l = 0; l < n; l++){
			mn = min(mn,dp[n-1][l][b]);
		}
		fout << mn << endl;
	}
	
}