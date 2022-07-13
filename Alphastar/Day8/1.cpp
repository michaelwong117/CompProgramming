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

vector<vpi> elev(500, vpi(500));
vector<vector<bool>> grid(500, vector<bool>(500));
multiv startpts;
vector<bool> seen(250001);


template<int SZ> struct DSU {
	int par[SZ], sz[SZ], int pts[SZ];
	DSU(){
		for(int i = 0; i < SZ; i++){
			par[i] = i; sz[i] = 1;
			if(grid[i][j])
	}
	int get(int x){
		if(par[x] != x) par[x] = get(par[x]);
		return par[x];
	}
	bool unite(int x, int y){
		int x = get(x), y = get(y);
		if(x == y) return 0;
		if(sz[x] < sz[y]) swap(x, y);
		sz[x] += sz[y]; par[y] = x;
		return 1;
	}
};

bool work(int d){
	DSU<250001> D;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < 4; k++){
				int nx = i+dx[k], ny = j+dy[k];
				if(nx >= 0 && nx < M && ny >= 0 && ny < N){
					if(abs(elev[i][j].f - elev[nx][ny].f) <= D){
						//valid edge, add to DSU
						D.unite(elev[i][j].s, elev[nx][ny].s);
					}
				}
			}
		}
	}
	for(int i = 0; i < startpts.size(); i++){
		if(D.sz[D.get(startpts[i][0])]-1 < T){
			return false;
		}
		else{
			seen[startpts[i][0]] = min(seen[startpts[i][0]], d);
		}
	}
	return true;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int M, N, T; cin >> M >> N >> T;
	int c = 1;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			cin >> elev[i][j].f; elev[i][j].s = c++;
		}
	}
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			cin >> grid[i][j];
			if(grid[i][j] == 1) startpts.pb({elev[i][j].s, i, j});
		}
	}
	int lo = 1, hi = 1e9;
	while(lo < hi){
		int mid = lo+(hi-lo)/2;
		if(work(mid)){
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	assert(work(lo));





}