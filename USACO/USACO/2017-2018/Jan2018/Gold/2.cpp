//g++-7 filename.cpp -std=c++14 -DH
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
#define out(x) cout << x << endl;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int mx = 1e5;

int N, K, dist[mx+1], distL[mx+1], par[mx+1], res = 0;
vector<vi> adj;
vi leaves;
bool s[mx+1];

void dfs(int root, int d){
	dist[root] = d;
	bool leaf = 1;
 	for(auto a: adj[root]){
		if(par[root] != a){
			leaf = 0;
			par[a] = root;
			dfs(a,d+1);	
		}
	}
	if(leaf) leaves.pb(root);
}
void bfs(){
	queue<pi> q;
	for(auto a: leaves){
		q.push({a,0}); distL[a] = 0;
	}
	while(!q.empty()){
		pi ft = q.front(); q.pop();
		s[ft.f]=1;
		for(auto a: adj[ft.f]){
			if(!s[a]){
				q.push({a,ft.s+1});
				distL[a] = min(distL[a],ft.s+1);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("atlarge.in","r",stdin); freopen("atlarge.out","w",stdout);	
	cin >> N >> K; adj.resize(N+1); 
	rep(i,N+1) distL[i]=1e9;
	for(int i = 0; i < N-1; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}	
	dfs(K,0); bfs();
	for(int i = 1; i <= N; i++){
		if(i == K) continue;
		//dist[i] >= distL[i] makes sure that we're checking the lowest one that works
		//only valid if
		//either dist[i] = distL[i]+1 if the path from root is even
		//or dist[i] = distL[i] if the path from root is odd
		if(dist[par[i]] < distL[par[i]] && dist[i] >= distL[i]) res++;
	}
	out(res);

}
