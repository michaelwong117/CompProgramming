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



template<int SZ> struct Tarjan {

	int time = 0; stack<int> S;

	vector<vi> adj, SCCs;
	vi visit, link;
	vector<bool> instack; 


	Tarjan(vector<vi> &adjT) {
		adj = adjT; visit.resize(SZ, -1); link.resize(SZ); instack.resize(SZ);
	}
	void strongC(int u){
		time++;
		visit[u] = time; link[u] = visit[u];
		S.push(u); instack[u] = 1;
		for(auto v: adj[u]){
			if(visit[v] == -1){ //if you haven't visited v
				strongC(v); //visit v
				link[u] = min(link[u], link[v]); //if v or v's children had back edges, update u
			}
			else if(instack[v]){ //cross edge case
				link[u] = min(link[u], visit[v]); //v is in component, acts as back edge
				//visit[v] or link[v] will work here for Tarjan
				//but for biconnected components you must use visit[v]
				//you are comparing >= in bcc
			}
			//if you've already visited v and it's not in stack, do nothing
		}
		if(visit[u] == link[u]){
			vi SCC;
			while(1){
				int v = S.top(); S.pop();
				SCC.pb(v); instack[v] = 0;
				if(u == v) break;
			}
			SCCs.pb(SCC);	
		}
	}
    
};


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);
	int n, m; cin >> n >> m;	
	vector<vi> adj (n+1);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
	}
	Tarjan<10001> T (adj);
	for(int i = 1; i <= n; i++){
		if(T.visit[i] == -1){
			T.strongC(i);
		}
	}
	int res = 0;
	for(auto a: T.SCCs){
		if(a.size() != 1) res++;
	}
	cout << res << endl;


}