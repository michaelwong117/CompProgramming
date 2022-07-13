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

int n, m, d[N], dp[501][N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> d[i];
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++) dp[i][j] = -1e9;
	}
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
		dp[0][i] = max(dp[0][i], dp[0][i-1]);
		for(int ex = 1; ex <= m; ex++){
			dp[ex][i] = max(dp[ex][i], dp[ex-1][i-1] + d[i]);
			if(i + ex <= n) dp[0][i+ex] = max(dp[0][i+ex], dp[ex][i]);
		}
	}
	cout << dp[0][n] << endl;
}