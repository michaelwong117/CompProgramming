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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	ll n, p, q, r; cin >> n >> p >> q >> r;
	vl a(n);

	ll dp[n+1][4];

	for(int i = 0; i < n; i++) cin >> a[i];

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= 3; j++){
			dp[i][j] = numeric_limits<ll>::min();
		}
	}
	dp[0][3] = p * a[0] + q * a[0] + r * a[0];
	dp[0][2] = p * a[0] + q * a[0];
	dp[0][1] = p * a[0];
	dp[0][0] = 0; 

	for(int i = 1; i < n; i++){
		dp[i][0] = max(dp[i][0], dp[i-1][0]);
		dp[i][1] = max(dp[i][1], dp[i-1][1]);
		dp[i][2] = max(dp[i][2], dp[i-1][2]);
		dp[i][3] = max(dp[i][3], dp[i-1][3]);

		dp[i][1] = max(dp[i][1], dp[i-1][0] + p * a[i]);

		dp[i][2] = max(dp[i][2], dp[i-1][1] + q * a[i]);
		dp[i][2] = max(dp[i][2], dp[i-1][0] + p * a[i] + q * a[i]);

		dp[i][3] = max(dp[i][3], dp[i-1][2] + r * a[i]);
		dp[i][3] = max(dp[i][3], dp[i-1][1] + q * a[i] + r * a[i]);
		dp[i][3] = max(dp[i][3], dp[i-1][0] + p * a[i] + q * a[i] + r * a[i]);

	}
	for(int i = 1; i < n; i++){
		dp[i][0] = max(dp[i][0], dp[i-1][0]);
		dp[i][1] = max(dp[i][1], dp[i-1][1]);
		dp[i][2] = max(dp[i][2], dp[i-1][2]);
		dp[i][3] = max(dp[i][3], dp[i-1][3]);

		dp[i][1] = max(dp[i][1], dp[i-1][0] + p * a[i]);

		dp[i][2] = max(dp[i][2], dp[i-1][1] + q * a[i]);
		dp[i][2] = max(dp[i][2], dp[i-1][0] + p * a[i] + q * a[i]);

		dp[i][3] = max(dp[i][3], dp[i-1][2] + r * a[i]);
		dp[i][3] = max(dp[i][3], dp[i-1][1] + q * a[i] + r * a[i]);
		dp[i][3] = max(dp[i][3], dp[i-1][0] + p * a[i] + q * a[i] + r * a[i]);

	}
	ll res = numeric_limits<ll>::min();
	for(int i = 0; i < n; i++){
		res = max(res, dp[i][3]);
	}
	out(res);


}