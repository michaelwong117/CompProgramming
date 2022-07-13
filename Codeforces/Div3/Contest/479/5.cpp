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
const int mx = 2*1e5;
int n, m, vis[mx+1], cl = 0;
vi adj[mx+1];

void dfs(int rt){
	for(auto a: adj[rt]){
		if(!vis[a]){
			vis[a] = cl; dfs(a);
		}
	}
}
void ccomp(){
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			vis[i] = ++cl; dfs(i); 
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("filename.out","w",stdout);	
	cin >> n >> m;
	rep(i, m){
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u); 
	}
	ccomp();
	vi v; v.resize(cl+1, 1);
	for(int i = 1; i <= n; i++){
		if(adj[i].size() != 2) v[vis[i]] = 0;
	}
	int res = 0;
	for(int i = 1; i <= cl; i++){
		if(v[i]) res++;
	}
	cout << res << endl;
	
}