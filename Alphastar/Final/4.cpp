//g++-7 filename.cpp -std=c++14
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e5;

int n, c, x[N], y[N], mx = 0;

unordered_set<int> s;

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
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= c) D.unite(i, j);
		}
	}
	int count = 0;
	for(int i = 0; i < n; i++){
		if(s.find(D.get(i)) == s.end()){
			count++; s.insert(D.get(i));
		}
		mx = max(D.sz[i], mx);
	}
	cout << count << " " << mx << endl;
}