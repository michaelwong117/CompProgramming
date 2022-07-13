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
const int N = 2*1e5+1;

int n, u, v, level[N], memo[N][3];

vi adj[N];

void prec(){
	queue<pi> q;
	q.push({1, 1}); level[1] = 1;
	while(!q.empty()){
		pi ft = q.front(); q.pop();
		for(auto a: adj[ft.f]){
			if(level[a]) continue;
			level[a] = ft.s+1;
			q.push({a, ft.s+1});
		}
	}
}

int calc(int root, int up){
	if(memo[root][up] != -1) return memo[root][up];

	int res = 0;

	if(root == 1){
		for(auto a: adj[root]){
			if(level[a] < level[root]) continue;
			res += calc(a, 0);
		}
		memo[root][up] = res;
		return res;
	}

	bool used = 0;
	
	for(auto a: adj[root]){
		if(level[a] < level[root]) continue;
		used = 1;
		if(up < 2){
			res += min(calc(a, up+1), calc(a, 0) + 1);
		}
		else{
			res += calc(a, 0) + 1;
		}
	}
	if(up == 2 && !used){
		memo[root][up] = 1e9;
		return 1e9;
	}
	memo[root][up] = res;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	prec();
	// for(int i = 1; i <= n; i++){
	// 	cout << i << " " << level[i] << endl;
	// }
	memset(memo, -1, sizeof memo);

	cout << calc(1, 0) << endl;

}
