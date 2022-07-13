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
const int mx = 1e5+1;
const int mxk = ceil(log2(mx));

vector<vi> P(mx, vi(mxk, -1)), adj;
vi level (mx);

void bfs(){
	queue<array<int,3>> q;
	//you set the parent of one equal to itself so that
	//anything that tries to go further gets set to one as well
	q.push({1, 1, 0});
	while(!q.empty()){

		array<int,3> ft = q.front(); q.pop();

		int cur = ft[0], par = ft[1], h = ft[2];

		level[cur] = h; P[cur][0] = par;

		for(int i = 0; i < adj[cur].size(); i++){
			if(P[adj[cur][i]][0] != -1) continue;
			q.push({adj[cur][i], cur, h+1});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n, q; cin >> n >> q;
	adj.resize(n+1);
	rep(i, n-1){
		int a, b; cin >> a >> b;
		adj[a].pb(b); adj[b].pb(a);
	}
	bfs();
	// for(int i = 1; i <= n; i++){
	// 	cout << i << " " << P[i][0] << " " << level[i] << endl;
	// }
	int end = ceil(log2(n));
	//cout << end << endl;
	for(int k = 1; k <= end; k++){
		//cout << "THIS IS K " << k << endl; 
		for(int i = 1; i <= n; i++){
			//cout << i << " " << P[i][k-1] << " "<<P[P[i][k-1]][k-1] << endl;
			P[i][k] = P[P[i][k-1]][k-1];
		}
	}
	rep(i, q){
		int a, b; cin >> a >> b;
		int tot = 0;
		// cout << a << " " << b << endl;		
		if(level[a] < level[b]) swap(a, b);
		int boost = a, dist = level[a]-level[b];
		//a = P[boost][dist];
		if(dist > 0){
			int k, cnt;
			for(k = 0, cnt = 1; cnt <= dist; k++, cnt *= 2){
				if(dist & cnt) boost = P[boost][k];
			}
		}
		tot += dist;

		a = boost;
		// cout << a << " " << b << endl;
		// cout << tot << endl;
		if(a == b){
			out(tot); continue;
		}
		for(int k = ceil(log2(n)); k >= 0; k--){
			if(P[a][k] != P[b][k]){
				a = P[a][k]; b = P[b][k];
			}
		}
		//cout << tot << " " << level[P[a][0]] << " " << level[boost] << endl;
		out(tot+2*(level[boost]-level[P[a][0]]));
	}
}