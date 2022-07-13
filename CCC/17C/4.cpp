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

int n, m, d;


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


vector<Edge> edges, edgesM;
vector<vector<Edge>> edgesV;

edges.pb({dist, u, v});

void MST(){
	DSU<250001> D;
	sort(all(edges));
	for(int i = 0; i < edges.size(); i++){
		if(!D.unite(edges[i].u, edges[i].v)) continue;
		int j = i+1;
		while(j < n && edges[i].w == edges[j].w){
			edgesV.pb(edgesM);
		}
		edgesM.pb({edges[i].w, edges[i].u, edges[i].v});
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> m >> d;
	for(int i = 0; i < m; i++){
		int a, b, c; cin >> a >> b >> c;
		if(i < n-1){

		}
	}
}

