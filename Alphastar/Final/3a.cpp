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
const int N = 5*1e4+1;

ll m, p[N], c[N], dp[2][N], res = -1e18;
int n, k;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> k >> m;
	for(int i = 1; i <= n; i++){
		cin >> p[i] >> c[i];
	}
	for(int i = 0; i < 2; i++){
		for(int j = 0; j <= k; j++){
			dp[i][j] = 1e18;
		}
	}
	for(int j = 0; j <= k; j++) dp[0][j] = 0;

	for(int i = 1; i <= n; i++){


		int prev = (i % 2 == 0) ? 1 : 0;
		int cur = (i % 2);
		// cout << i << endl;
		for(int j = 0; j <= min(i, k); j++){

			// cout << "INITIAL " << dp[cur][j] << endl;
			// cout << dp[prev][j] + p[i] << " " << dp[prev][j] + c[i] << endl;

			dp[cur][j] = min(dp[cur][j], dp[prev][j] + p[i]);
			if(j != 0) dp[cur][j] = min(dp[cur][j], dp[prev][j-1] + c[i]);
			if(dp[cur][j] <= m) res = max(res, (ll) i);
		}


		for(int j = 0; j <= min(i, k); j++){
			//cout << i << " " << j << " " << dp[cur][j] << endl;
			dp[prev][j] = 1e18;
		}

	}
	out(res);
}