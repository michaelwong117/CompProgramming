//#pragma GCC optimize("Ofast")

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

int dx[]={ 0, 0,+1,-1};
int dy[]={+1,-1, 0, 0};

struct Edge {
	int w, u, v;
	bool operator < (const Edge &e) const {
		return this->w < e.w;
	}
};

vector<vpi> elev(500, vpi(500));
vector<bool> startpts (250000);
multiv edgesM;
vector<Edge> edges;

bool cmp(array<int,3> a, array<int,3> b){
	return (a[0] < b[0]);
}

template<int SZ> struct DSU {
	int par[SZ], sz[SZ], pts[SZ];
	DSU(){
		for(int i = 0; i < SZ; i++){
			par[i] = i; sz[i] = 1; pts[i] = 0;
			if(startpts[i]) pts[i] = 1;
		}
	}
	int get(int x){
		if(par[x] != x) par[x] = get(par[x]);
		return par[x];
	}
	bool unite(int x, int y){
		x = get(x), y = get(y);
		if(x == y) return 0;
		if(sz[x] < sz[y]) swap(x, y);
		sz[x] += sz[y]; pts[x] += pts[y]; par[y] = x;
		return 1;
	}
};


void MST(){
	DSU<250001> D;
	sort(all(edges));
	for(int i = 0; i < edges.size(); i++){
		if(!D.unite(edges[i].u, edges[i].v)) continue;
		edgesM.pb({edges[i].w, edges[i].u, edges[i].v});
	}
}

//transform graphs into trees
//the mst minimizes the maximum edge between any two nodes
//find the best path that minimizes the maximum edge


//use mst to transform a graph into a tree graph
//use lca and binary juumping to find the minimum distance between two ndoes in a tree



int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int M, N, T; cin >> M >> N >> T;
	int c = 0;
	//START
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			cin >> elev[i][j].f; elev[i][j].s = c++;
		}
	}
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			int x; cin >> x;
			if(x == 1) startpts[elev[i][j].s] = 1;

		}
	}
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < 4; k++){
				int nx = i+dx[k], ny = j+dy[k];
				if(nx >= 0 && nx < M && ny >= 0 && ny < N){
					edges.pb({abs(elev[i][j].f - elev[nx][ny].f), elev[i][j].s, elev[nx][ny].s});
				}
			}
		}
	}
	MST();

	DSU<250000> Final;
	ll sum = 0;
	int d = -1e9;
	for(int i = 0; i < edgesM.size(); i++){
		if(edgesM[i][0] > d) d = edgesM[i][0];
		
		Final.unite(edgesM[i][1], edgesM[i][2]);
		int group = Final.get(edgesM[i][2]);
		if(Final.sz[group] >= T){
			ll points = Final.pts[group];
			sum += (ll) d * points;
			Final.pts[group] = 0;

		}
		
		//cout << edgesM[i][0] << " " << edgesM[i][1] << " " << edgesM[i][2] << endl;
	}
	out(sum);
	//STOP





}