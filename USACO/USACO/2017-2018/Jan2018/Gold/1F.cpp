//g++ filename.cpp -std=c++14 -DH
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define endl '\n'
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>>
#define mpq priority_queue<int>
 
typedef long long ll; typedef vector<int> vi;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int maxN = 1e5+1;
int N, Q, res[maxN];
multiv v, q;

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
 
DSU<100001> D;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("mootube.in"); ofstream fout("mootube.out");
	fin >> N >> Q;
	for(int i = 0; i < N-1; i++){
		int p, q, r; fin >> p >> q >> r;
		v.pb({r,p,q});
	}
	for(int i = 0; i < Q; i++){
		int k, v; fin >> k >> v;
		q.pb({k,v,i});
	}
	sort(v.rbegin(), v.rend()); sort(q.rbegin(), q.rend());
	int j = 0;
	for(int i = 0; i < Q; i++){
		while(j < N && v[j][0] >= q[i][0]){
			D.unite(v[j][1], v[j][2]);
			j++;
		}
		res[q[i][2]] = D.sz[D.get(q[i][1])]-1;
	}
	for(int i = 0; i < Q; i++) fout << res[i] << endl;

}