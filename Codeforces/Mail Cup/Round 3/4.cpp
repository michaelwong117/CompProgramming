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
const int N = 1e5+1;

vi adj[N];
int sz[N], p[N], s[N];

priority_queue<pi, vector<pi>, greater<pi>> q;

void dfs(int rt){
	bool leaf = 1;
	for(auto a: adj[rt]){
		if(!p[a]){
			leaf = 0;
			p[a] = rt;
			dfs(a);
			sz[rt] += sz[a];
		}
	}
	if(leaf) sz[rt] = 1;
}


void bfs(){
	while(!q.empty()){
		pi ft = q.top(); q.pop();
		cout << ft.f << " ";
		// cout << ft.s << " " << ft.f << endl;
		for(auto a: adj[ft.s]){
			if(!s[a]){
				s[a] = 1;
				//cout << sz[a] << " ";
				q.push({sz[a], a});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	int n; cin >> n;
	for(int i = 2; i <= n; i++){
		int p; cin >> p;
		adj[i].pb(p); adj[p].pb(i);
	}
	p[1] = 1;
	dfs(1);
	for(int i = 1; i <= n; i++){
		if(sz[i] == 1){
			q.push({1,i}); s[i] = 1;
		}
		// cout << i << " " << sz[i] << endl;
	}
	bfs();






}
