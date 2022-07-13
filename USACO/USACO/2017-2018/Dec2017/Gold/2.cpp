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
const int N = 1e5+1;

vi adj[N];

int n, k, setcol[N];
ll dp[4][N];

//key part of dp recursion: if you calculated it, return it!!

ll solve(int root, int curC, int parC, int par){
	if(curC == parC || ((setcol[root]) && setcol[root] != curC)) return 0;
	if(dp[curC][root] >= 0) return dp[curC][root]; //KEY LINE!!!!!
	dp[curC][root] = 1;
	for(auto a: adj[root]){
		if(a == par) continue;
		ll sum = 0;
		for(int c = 1; c <= 3; c++){
			sum += solve(a, c, curC, root);
			sum %= MOD;
		}
		dp[curC][root] = (dp[curC][root] * sum % MOD) % MOD; //extra mod is important

	}
	return dp[curC][root];
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("barnpainting.in","r",stdin); freopen("barnpainting.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> k;
	for(int i = 0; i < n-1; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y); adj[y].pb(x);
	}
	for(int i = 0; i < k; i++){
		int b, c; cin >> b >> c;
		setcol[b] = c;
	}
	ll res = 0;
	for(int c = 1; c <= 3; c++){
		for(int i = 1; i <= n; i++){
			dp[c][i] = -1;
		}
	}
	for(int c = 1; c <= 3; c++){
		res = (res + solve(1, c, -1, -1) % MOD) % MOD;
	}
	cout << res << endl;

}
