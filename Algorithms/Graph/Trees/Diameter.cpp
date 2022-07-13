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
int n, t, u;
bool A[maxN];
vector<vi> adj;
//flag to check for distance between two nodes
int furthest(int root, int flag){
	int res, mx = 0;
	queue<pi> q;
	q.push({root, 0});
	A[root] = 1;
	while(!q.empty()){
		pi ft = q.front(); q.pop();
		if(ft.f == flag) return ft.s;
		if(ft.s > mx){
			mx = ft.s;
			res = ft.f;
		}
		for(auto a: adj[ft.f]){
			if(!A[a]) A[a] = 1;
			else continue;
			q.push({a, ft.s+1});
		}
	}
	memset(0, sizeof A, 0)
	for(int i = 0; i < sizeof A; i++) A[i] = 0;
	return res;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("filename.in"); ofstream fout("filename.out");
	cin >> n;
	adj.resize(n+1);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	t = furthest(1, -1);
	u = furthest(t, -1);
	cout << furthest(u, t) << endl;
	
	
}
//center minimizes remoteness (distance from furthest node)
//all diameters must past through centroid
//when you remove centroid, split graph into forests of [n/2] size max
//great for divide and conquer
//centroid minimizes maximum forest when it's removed
//at most two diameters and centers








