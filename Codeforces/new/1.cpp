//g++-7 filename.cpp -std=c++14
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>> //min pq
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

int n, v, dp[110][110];

int solve(int idx, int fuel){
	if(idx == n) return 0;
	if(dp[idx][fuel] != 1e9){
		return dp[idx][fuel];
	}
	int res = 1e9;
	for(int i = 1; i <= v; i++){
		if(fuel+i > v) continue;
		for(int j = 1; j <= fuel+i; j++){
			if(j+idx > n) continue;
			res = min(res, solve(j+idx, fuel + i - j) + i * idx);
		}
	}
	return dp[idx][fuel] = res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> v;
	for(int i = 0; i < 110; i++){
		for(int j = 0; j < 110; j++){
			dp[i][j] = 1e9;
		}
	}
	cout << solve(1, 0) << endl;
	
}
