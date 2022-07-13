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

int n, m;

template<int SZ> struct DSU {
    int par[SZ], rank[SZ];
    DSU() {
        for(int i = 0; i < SZ; i++) par[i] = i, rank[i] = 0;
    }
    int get(int x) { // path compression
        if (par[x] != x) par[x] = get(par[x]);
        return par[x];
    }
    bool unite(int x, int y) { // union-by-rank
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (rank[x] < rank[y]) swap(x,y);
        par[y] = x;
        if(rank[x] == rank[y]) rank[y]++;
        return 1;
    }
};

DSU<100001> D;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> m;
	if(n == 1){
		cout << "YES" << endl;
		return 0;
	}
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		if(!D.unite(u, v)){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}