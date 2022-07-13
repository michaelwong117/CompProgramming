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
const int N = 10001;

template<int SZ> struct Prims {
	ll dist[SZ];
	pl par[SZ];
	bool in[SZ];
	Prims (int st, vector<vpi> & adj) {

		for(int i = 1; i < SZ; i++) dist[i] = 1e18, in[i] = 0;

		dist[st] = 0; par[st] = {-1, 0};

		while(1){
			ll best = 1e18, cur = -1;
			for(int i = 1; i < SZ; i++){
				if(in[i]) continue;
				if(dist[i] < best){
					best = dist[i]; cur = i;
				}
			}
			if(cur == -1) break;
			in[cur] = 1;
			for(auto a: adj[cur]){
				if(in[a.f]) continue;
				if(a.s < dist[a.f]){
					dist[a.f] = a.s;
					par[a.f] = {cur, a.s};
				}
			}
		}
	}
};

int n, m;
vector<vpi> adj(N);

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v, w; cin >> u >> v >> w;
		adj[u].pb({v, w});  adj[v].pb({u, w});
	}
	Prims<N> P (1, adj);
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		sum += P.par[i].s;
		//MST
		//cout << P.par[i].f << " " << i << " " << P.par[i].s << endl;
	}
	cout << sum << endl;


}