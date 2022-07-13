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

int n, m, k;

const int N = 5*1e4+1;

vector<vpi> adj (N+1);

int idx[N], yum[N];

template<int SZ> struct Dijkstra {
	priority_queue<pi, vector<pi>, greater<pi>> q;
	int dist[SZ];
	Dijkstra(int start, vector<vpi> & adj) {
		for(int i = 0; i < SZ; i++) dist[i] = 1e9;
		dist[start] = 0; q.push({0, start});
		while(!q.empty()){
			pi ft = q.top(); q.pop();
			if(dist[ft.s] < ft.f) continue; //never visit a minimum node again
			for(auto a: adj[ft.s]){
				if(dist[a.f] > ft.f + a.s){
					dist[a.f] = ft.f + a.s;
					q.push({dist[a.f], a.f});
				}
			}
		}
	}

};


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("dining.in","r",stdin); freopen("dining.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	for(int i = 1; i <= k; i++){
		cin >> idx[i] >> yum[i];
	}
	Dijkstra<N> best(n, adj);

	for(int i = 1; i < n; i++){
		bool found = 0;
		Dijkstra<N> SP(i, adj);
		for(int j = 1; j <= k; j++){
			if(SP.dist[idx[j]] + best.dist[idx[j]] - best.dist[i] <= yum[j]){
				found = 1; break;
			}
		}
		if(found){
			cout << 1 << endl;
		}
		else{
			cout << 0 << endl;
		}
	}

	
}
