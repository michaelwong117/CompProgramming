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
#define heap priority_queue<int>
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;
typedef vector<array<int,3>> multiv;
const int maxN = 501;

int n, m, cycle = 0, seen[maxN];
vector<vi> adj (maxN);

//0 is not explored
//-1 is being explored
//1 is finished being explored

void dfs(int c){
	seen[c] = -1;
	for(int i = 0; i < adj[c].size(); i++){
		if(seen[adj[c][i]] == 0) dfs(adj[c][i]);
		else if(seen[adj[c][i]] == -1){
			cycle = 1;
			return;
		}
	}
	seen[c] = 1;
}

bool isCycle(){
	for(int i = 1; i <= n; i++){
		if(seen[i] != 1) dfs(i);
		if(cycle) return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	fin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		fin >> u >> v;
		adj[u].pb(v);
	}
	cout << isCycle() << endl;
	


}