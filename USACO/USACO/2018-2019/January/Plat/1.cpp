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

int n, k;

char a[3*100000+1];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("redistricting.in","r",stdin); //freopen("redistricting.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];

	vector<vpi> dp(k+1, vpi(n+1, {1e9, 1e9}));


	int val = (a[1] == 'G') ? 1: -1;


	dp[1][1] = {0, val};
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= min(i,k); j++){
			pi self = dp[j][i];
			val = (a[i+1] == 'G') ? 1: -1;
			if(j == k) dp[1][i+1] = min(dp[1][i+1], {(self.s >= 0) + self.f, val});
			else dp[j+1][i+1] = min(dp[j+1][i+1], {self.f, self.s+val});
			dp[1][i+1] = min(dp[1][i+1], {(self.s >= 0) + self.f, val});
		}
	}
	// cout << dp[1][1].f << " " << dp[1][1].s << endl;
	// cout << dp[1][2].f << " " << dp[1][2].s << endl;
	// cout << dp[2][2].f << " " << dp[2][2].s << endl;

	int ans = 1e9;
	for(int i = 1; i <= k; i++){
		ans = min(ans, dp[i][n].f + (dp[i][n].s >= 0));
	}
	cout << ans << endl;

}
