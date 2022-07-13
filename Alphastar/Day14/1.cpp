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
int sz[N], p[N], dp[2][N], n, mxh = -1e9;
vector<vi> adj, row (N), subtree (N);

void bfs(){
	queue<pi> q;
	q.push({1, 1}); p[1] = 1; row[1].pb(1);
	while(!q.empty()){
		pi ft = q.front(); q.pop();
		for(auto a: adj[ft.f]){
			if(p[a]) continue;
			p[a] = ft.f; sz[ft.f]++; 

			subtree[ft.f].pb(a);
			q.push({a, ft.s+1}); row[ft.s+1].pb(a);
			mxh = max(mxh, ft.s+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);
	cin >> n;
	adj.resize(n+1);
	for(int i = 0; i < n; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	bfs();
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < N; j++){
			dp[i][j] = -1e9;
		}
	}
	for(auto leaf: row[mxh]){
		dp[1][leaf] = 1;
		dp[0][leaf] = 0;
	}
	for(int i = mxh-1; i >= 1; i--){
		for(auto root: row[i]){
			int val1 = 0, val2 = 0;
			for(auto dir: subtree[root]){
				val1 += max(dp[0][dir], dp[1][dir]);
				val2 += dp[0][dir];
			}
			dp[0][root] = max(dp[0][root], val1);
			dp[1][root] = max(dp[1][root], val2+1);
		}
	}
	cout << max(dp[0][1], dp[1][1]) << endl;





}