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

int n, m, seen[maxN];
bool cycle, firstCheck = 1;
pi omit;
vector<vi> adj (maxN);
vpi E;
//0 is not explored
//-1 is being explored
//1 is finished being explored
void dfs(int c){
	seen[c] = -1;
	for(int i = 0; i < adj[c].size(); i++){
		if(!firstCheck){
			if(omit == pi(c,adj[c][i])) continue;
		}
		if(firstCheck) E.pb({c,adj[c][i]});
		if(seen[adj[c][i]] == 0) dfs(adj[c][i]);
		if(seen[adj[c][i]] == -1){
			cycle = 1;
			return;
		}
	}
	seen[c] = 1;
}
bool isCycle(){
	for(int i = 1; i <= n; i++){
		if(seen[i] != 1){
			if(firstCheck) E.clear();
			dfs(i);
		}
		if(cycle) return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}
	if(!isCycle()){
		cout << "YES" << endl;
		return 0;
	}
	firstCheck = 0;
	for(int i = 0; i < E.size(); i++){
		omit = E[i];
		cycle = 0;
		for(int i = 0; i <= n; i++) seen[i] = 0;
		if(!isCycle()){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	


}