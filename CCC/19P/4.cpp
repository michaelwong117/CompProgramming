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

int n;

map<pi, vi> m;
map<pi, int> ed;

struct Edge {
	int w, u, v;
	bool operator < (const Edge &e) const {
		return this->w < e.w;
	}
};


template<int SZ> struct DSU {
    int par[SZ], sz[SZ];
    DSU() {
        for(int i = 0; i < SZ; i++) par[i] = i, sz[i] = 1;
    }
    int get(int x) { // path compression
        if (par[x] != x) par[x] = get(par[x]);
        return par[x];
    }
    bool unite(int x, int y) { // union-by-rank
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (sz[x] < sz[y]) swap(x,y);
        sz[x] += sz[y], par[y] = x;
        return 1;
    }
};


vector<Edge> edges, edgesM, edges2, edgesM2;

//MAKING AN ADDITIONAL NODE REACHABLE BY EVERYTHING
//WITH MINIMUM EDGE COST IS THE SAME THING AS TAKING AN 
//MST OVER THE WHOLE GRAPH WITH THE ADDED NODE

void MST(){
	DSU<10001> D;
	sort(all(edges));
	for(int i = 0; i < edges.size(); i++){
		if(!D.unite(edges[i].u, edges[i].v)) continue;
		edgesM.pb({edges[i].w, edges[i].u, edges[i].v});
	}
}
void MST2(){
	DSU<10001> D;
	sort(all(edges2));
	for(int i = 0; i < edges2.size(); i++){
		if(!D.unite(edges2[i].u, edges2[i].v)) continue;
		edgesM2.pb({edges2[i].w, edges2[i].u, edges2[i].v});
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;
	for(int nd = 1; nd <= n; nd++){
		int e; cin >> e;
		vi v (e), cost (e);
		for(int i = 0; i < e; i++){
			cin >> v[i];
		}
		for(int i = 0; i < e; i++){
			cin >> cost[i];
		}
		for(int i = 1; i < e; i++){
			pi p = {v[i-1], v[i]};

			if(p.f > p.s) swap(p.f, p.s);
			// cout << p.f << " " << p.s << endl;
			if(m.find(p) == m.end()){
				m[p] = {nd};
				ed[p] = cost[i-1];
			}
			else m[p].pb(nd);
			//add(v[i-1], v[i]) equivalent to v[i], v[i-1]
			//with some cost c[i-1]
		}
		pi p = {v[0], v[e-1]};

		if(p.f > p.s) swap(p.f, p.s);
		// cout << p.f << " " << p.s << endl;
		if(m.find(p) == m.end()){
			m[p] = {nd};
			ed[p] = cost[e-1];
		}
		else m[p].pb(nd);
	}
	// for(auto a: m){
	// 	cout << "EDGE " << a.f.f << " " << a.f.s << endl;
	// 	cout << "COST " << ed[a.f] << endl;
	// 	cout << "SHARED BY: " << a.s.size() << endl;
	// 	for(auto b: a.s){
	// 		cout << b << " ";
	// 	}
	// 	cout << endl << endl;
	// }
	for(auto a: m){
		if(a.s.size() > 2){
			cout << "BAD" << endl;
			return 0;
		}
		//add edge between a.s[0] and a.s[1]
		if(a.s.size() == 2){
			// cout << ed[a.f] << " " << a.s[0] << " " << a.s[1] << endl;
			edges.pb({ed[a.f], a.s[0], a.s[1]});
			edges2.pb({ed[a.f], a.s[0], a.s[1]});
		}
		else{
			//cout << ed[a.f] << " " << n+1 << " " << a.s[0] << endl;
			edges2.pb({ed[a.f], n+1, a.s[0]});
		}

	}
	MST();
	MST2();
	ll res = 0, res2 = 0;
	for(auto a: edgesM){
		res += a.w;
	}
	for(auto a: edgesM2){
		res2 += a.w;
	}
	cout << min(res,res2) << endl;
}
