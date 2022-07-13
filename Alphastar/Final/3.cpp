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

ll m, p[N], c[N];
pl dp[2][N];
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
			dp[i][j] = {-1e18, 1e18};
		}
	}

	dp[0][0] = {0, 0};

	for(int i = 1; i <= n; i++){


		int prev = (i % 2 == 0) ? 1 : 0;
		int cur = (i % 2);

		for(int j = 0; j <= min(i, k); j++){


			// cout << "FIRSTCHECK" << endl;
			// cout << dp[prev][j].f << " " << dp[cur][j].f << endl;
			// cout << dp[prev][j].s << " " << dp[cur][j].s << endl;

			if(dp[prev][j].f == dp[cur][j].f){
				dp[cur][j] = {dp[cur][j].f, min(dp[prev][j].s, dp[cur][j].s)};
			}

			else if(dp[prev][j].f > dp[cur][j].f){
				dp[cur][j] = dp[prev][j];
			}
			

			// cout << "SECONDCHECK" << endl;
			// cout << dp[prev][j].f << " " << dp[cur][j].f << endl;
			// cout << dp[prev][j].s << " " << dp[cur][j].s << endl;


			if(dp[prev][j].f + 1 > dp[cur][j].f && dp[prev][j].s + p[i] <= m){

				dp[cur][j] = {dp[prev][j].f + 1, 

					dp[prev][j].s + p[i]};
			}

			if(dp[prev][j].f + 1 == dp[cur][j].f){

				dp[cur][j] = {dp[prev][j].f + 1, 

					min(dp[cur][j].s, dp[prev][j].s + p[i])};
			}

			// cout << "THIRDCHECK" << endl;
			// cout << dp[prev][j].f << " " << dp[cur][j].f << endl;
			// cout << dp[prev][j].s << " " << dp[cur][j].s << endl;

			//if(dp[cur][j].s <= m) res = max(res, dp[cur][j].f);

			if(j == 0) continue;


			if(dp[prev][j-1].f + 1 > dp[cur][j].f && dp[prev][j-1].s + c[i] <= m){

				dp[cur][j] = {dp[prev][j-1].f + 1, 

					dp[prev][j-1].s + c[i]};

			}

			if(dp[prev][j-1].f + 1 == dp[cur][j].f){

				dp[cur][j] = {dp[prev][j-1].f + 1, 

					min(dp[cur][j].s, dp[prev][j-1].s + c[i])};

			}

			// cout << "FOURTHCHECK" << endl;
			// cout << dp[prev][j].f << " " << dp[cur][j].f << endl;
			// cout << dp[prev][j].s << " " << dp[cur][j].s << endl;

			assert((dp[cur][j].s <= m || dp[cur][j].s == 1e18));

		}
		// for(int j = 0; j <= min(i, k); j++){
		// 	cout << dp[cur][j].f << " " << dp[cur][j].s << endl;
		// }
		for(int j = 0; j <= min(i, k); j++){
			dp[prev][j] = {-1e18, 1e18};
		}
	}
	ll res = -1e18;
	for(int j = 0; j <= k; j++){
		//cout << dp[n % 2][j].f << " " << dp[n % 2][j].s << endl;
		res = max(res, dp[n % 2][j].f);
	}
	out(res);
}