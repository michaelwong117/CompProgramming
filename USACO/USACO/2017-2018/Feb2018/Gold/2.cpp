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
 
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int mx = 1e5+1;
ll sol = 1e18;
int N, w[mx], sz[mx];
vector<vi> adj;
ll dfs(int root, ll sum){
	if(adj[root].empty()){
		sz[root] = 1;
		return sum-1;
	}
	ll res = 0;
	for(auto a: adj[root]){
		res += dfs(a, sum+w[a]+1);
		sz[root] += sz[a];
	}
	return res;
}
void split(int root, ll sum){
	if(adj[root].empty()) return;
	sol = min(sol, sum);
	for(auto a: adj[root]) split(a, (sum-sz[a]*(w[a]+1))+3*(sz[1]-sz[a]));
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("dirtraverse.in"); ofstream fout("dirtraverse.out");
	fin >> N; adj.resize(N+1);
	for(int i = 1; i <= N; i++){
		string s; fin >> s;
		w[i] = s.length();
		int m; fin >> m;
		for(int i2 = 0; i2 < m; i2++){
			int v; fin >> v;
			adj[i].pb(v);
		}
	}
	split(1,dfs(1,0));
	fout << sol << endl;
}