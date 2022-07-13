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

const int N = 1e4+1;
const int K = 1e3+1;

int mx[N][K], dp[K][N], v[N];

int n, k;


int solve(int cow, int prev){
	if(cow == n){
		return mx[prev][cow - 1 - prev] * (cow - prev);
	}
	
	if(dp[cow-prev][prev] != -1)
		return dp[cow-prev][prev];

	if(cow - prev == k){
		dp[k][prev] = k * mx[prev][k - 1] + solve(cow, cow);
		return dp[cow-prev][prev];
	}
		
	int res = 0; //set result
	
	res = max(res, solve(cow + 1, prev));
	if(cow != prev){
		res = max(res, solve(cow, cow) + mx[prev][cow - 1 - prev] * (cow - prev));
	}
	
	dp[cow - prev][prev] = res;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("teamwork.in","r",stdin); freopen("teamwork.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= k; j++){
			if(j-1 >= 0) mx[i][j] = max(mx[i][j], max(mx[i][j-1], v[i+j]));
			else mx[i][j] = max(mx[i][j], v[i+j]);
		}
	}
	for(int i = 0; i <= k; i++){
		for(int j = 0; j < n; j++){
			dp[i][j] = -1;
		}
	}

	cout << solve(1, 0) << endl;

}
