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

const int N = 1001;

vi p(N), level(N), s(N);

vector<vi> adj(N);

void bfs(int root){
	queue<pi> q;
	q.push({root, level[p[root]]+1});
	while(!q.empty()){
		pi ft = q.front(); q.pop();
		// cout << ft.f << " " << ft.s << endl;
		for(auto a: adj[ft.f]){
			//cout << a << endl;
			if(s[a]) continue;
			s[a] = ft.f; 
			level[a] = ft.s+1;
			q.push({a, ft.s+1});
		}
	}
}



int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int par; cin >> par;
		p[i] = par;
		adj[par].pb(i);
		if(i == par) continue;
		adj[i].pb(par);
		//cout << i << " " << par << endl; 
	}
	p[1] = 1; level[1] = 1; 
	for(int i = 1; i <= n; i++){
		bfs(i);
	}
	for(int i = 1; i <= n; i++) out(p[i]);
	cout << endl;
	for(int i = 1; i <= n; i++) out(level[i]);
	
}