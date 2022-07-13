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
#define pq priority_queue<int, vector<int>, greater<int>>
#define mpq priority_queue<int>
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

vpi coins(100);

int n, t;

int calc(int val){
	vi dp(val+1, 1e9);
	dp[0] = 0;
	for(int c = 0; c < n; c++){
		for(int i = 0; i <= val-coins[c].f; i++){
			dp[i+coins[c].f] = min(dp[i+coins[c].f], dp[i]+1);
		}
	}
	return dp[val];
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> t;
	int maxval = -1;
	for(int i = 0; i < n; i++){
		cin >> coins[i].f;
		maxval = max(maxval, coins[i].f);
	}
	for(int i = 0; i < n; i++) cin >> coins[i].s;
	vi dp (t+maxval+1, 1e9);
	dp[0] = 0;
	for(int c = 0; c < n; c++){
		for(int sz = 1; sz <= coins[c].s; sz++){
			for(int w = t+maxval - coins[c].f; w >= 0; w--){
				dp[w + coins[c].f] = min(dp[w + coins[c].f], dp[w] + 1);
			}
		}
	}
	int res = dp[t];
	for(int i = t+1; i <= t+maxval; i++){
		//cout << i << " " << dp[i] << " " << calc(i-t) << endl;
		res = min(res, dp[i]+calc(i-t));
	}
	if(res == 1e9) cout << -1 << endl;
	else cout << res << endl;
	// for(int i = 0; i <= t+maxval; i++){
	// 	if(dp[i] < 1e9) cout << i << " " << dp[i] << endl;
	// }

}