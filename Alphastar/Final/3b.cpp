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

ll m, p[N], c[N], dp[N][2], res = -1e18;
int n, k;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> k >> m;
	for(int i = 1; i <= n; i++){
		cin >> p[i] >> c[i];
	}
	for(int i = 0; i <= n; i++){
		dp[i][0] = 1e18;
		dp[i][1] = 1e18;
		
	}
	dp[0][0] = 0, dp[0][1] = 0;

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 2; j++){
			if(k > i){
				dp[i][0] = min(dp[i][0], dp[i-1][1] + c[i]);
				dp[i][0] = min(dp[i][0], dp[i-1][1] + p[i]);
				dp[i][0] = min(dp[i][0], dp[i-1][0] + c[i]);
				dp[i][0] = min(dp[i][0], dp[i-1][0] + p[i]);

				dp[i][1] = min(dp[i][0], dp[i-1][1] + p[i]);
				dp[i][1] = min(dp[i][0], dp[i-1][1] + c[i]);
				dp[i][1] = min(dp[i][0], dp[i-1][0] + p[i]);
				dp[i][1] = min(dp[i][0], dp[i-1][0] + c[i]);
			}
			else{
				dp[i][1] = min(dp[i][1], c[i] + dp[i-1][0]);
				dp[i][1] = min(dp[i][1], p[i] + dp[i-1][1]);
				dp[i][0] = min(dp[i][1], p[i] + dp[i-1][0]);
			}
		}
	}
	for(int i = 0; i <= n; i++){
		cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
		if(dp[i][0] <= m) res = i;
		if(dp[i][1] <= m) res = i;
	}
	out(res);
}