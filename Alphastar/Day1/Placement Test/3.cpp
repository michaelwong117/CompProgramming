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

const int N = 1001;

template<int SZ> struct Dijkstra {
	priority_queue<pl, vector<pl>, greater<pl>> q;
	ll dist[SZ];
	Dijkstra(int start, vector<vpi> & adj, ll mx) {
		for(int i = 0; i < SZ; i++) dist[i] = 1e18;
		dist[start] = 0; q.push({0, start});
		while(!q.empty()){
			pl ft = q.top(); q.pop();
			if(dist[ft.s] < ft.f) continue; //never visit a minimum node again
			for(auto a: adj[ft.s]){
				if(dist[a.f] > ft.f + ((ll) a.s > mx)){
					dist[a.f] = ft.f + ((ll) a.s > mx);
					q.push({dist[a.f], a.f});
				}
			}
		}
	}

};


ll n, p, k;
ll sumE = 0;
vector<vpi> adj (N);


bool f(ll mx){
	Dijkstra<N> D (1, adj, mx);
	if(D.dist[n] > (ll) k) return false;
	else return true;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> p >> k;
	for(int i = 0; i < p; i++){
		int u, v, w; cin >> u >> v >> w;
		sumE += (ll) w;
		adj[u].pb({v, w}); adj[v].pb({u, w}); //Dijkstra
	}
	ll lo = 0, hi = sumE;
	while(lo < hi){
		ll mid = lo + (hi-lo) / 2;
		bool check = f(mid);
		if(check) hi = mid;
		else lo = mid+1;
	}
	if(f(lo) == false) cout << -1 << endl;
	else cout << lo << endl;

	
	
}