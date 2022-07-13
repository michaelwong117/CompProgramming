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
const int mx = 1e5+100;

vector<vector<pl>> adj(mx);


vl C(mx), dist(mx), sz(mx);
vector<bool> p(mx);

ll n;

ll dfs(ll root, ll cur){
	bool none = 1;
	ll res = 0;
	sz[root] += C[root];
	for(auto a: adj[root]){
		if(p[a.f]) continue;
		none = 0; p[a.f] = root;
		res += dfs(a.f, cur+C[root]);
		sz[root] += sz[a.f];
	}
	if(none){
		sz[root] = C[root]; return C[root];
	}
	return res;
}

ll bfs(ll root){
	ll res = 0;
	queue<pl> q;
	q.push({root, 0});
	fill(all(p),0);
	p[root] = 1;
	while(!q.empty()){
		pl ft = q.front(); q.pop();
		for(auto a: adj[ft.f]){
			if(p[a.f]) continue;
			p[a.f] = ft.f;
			q.push({a.f, ft.s+a.s});
			res += sz[a.f]*a.s;
		}
	}
	return res;
}

ll bfsF(ll root){
	ll res = 1e18;
	queue<pl> q;
	q.push({root, dist[1]});
	while(!q.empty()){
		pl ft = q.front(); q.pop();
		ll sum = sz[1];
		for(auto a: adj[ft.f]){
			if(dist[a.f]) continue;
			// cout << ft.f << " " << a.f << " " << a.s << endl;
			// cout << dist[ft.f] << " " << sz[a.f] << " " << C[ft.f] << " " << (sum-sz[a.f]) << endl;
			dist[a.f] = dist[ft.f] - (sz[a.f] * a.s) + ((sum - sz[a.f]) * a.s);
			res = min(res, dist[a.f]);
			q.push({a.f, dist[a.f]});

		}
	}
	return res;
}





int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);
	cin >> n;
	rep(i, n){
		cin >> C[i+1]; 
	}
	rep(i, n){
		ll x, y, l; cin >> x >> y >> l;
		adj[x].pb({y, l});
		adj[y].pb({x, l});
	}
	p[1] = 1;
	dfs(1, 0);
	dist[1] = bfs(1);
	out(min(dist[1],bfsF(1)));
	//cout << dist[1] << endl;
	// rep(i, n){
	// 	cout << i+1 << " " << p[i+1] << endl;
	// }
	// rep(i, n){
	// 	cout << i+1 << " " << sz[i+1] << endl;
	// }






}