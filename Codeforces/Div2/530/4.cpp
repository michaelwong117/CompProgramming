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

int n, p[100001], s[100001];
ll res = 0;

bool imp = false;

vector<vi> adj (100001);

void bfs(){

	queue<pi> q;	

	q.push({1, 1});

	while(!q.empty()){
		pi ft = q.front(); q.pop();
		int parS = s[p[ft.f]];
		if(ft.s == 0){
			int mn = 1e9;
			for(auto a: adj[ft.f]){
				mn = min(mn, s[a]-parS);
				q.push({a, 1});
			}
			for(auto a: adj[ft.f]){
				if(s[a] - parS < 0){
					imp = 1;
				}
				else res += (ll) ((s[a] - parS) - mn);
			}
			if(adj[ft.f].size()) res += mn;
		}
		else{
			for(auto a: adj[ft.f]){
				q.push({a, 0});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;
	for(int i = 2; i <= n; i++){
		int par; cin >> par;
		p[i] = par;
		adj[par].pb(i); 
	}
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	res = s[1];
	bfs();
	if(imp){
		cout << -1 << endl;
	}
	else cout << res << endl;
}
