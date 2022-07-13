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

const int M = 5*1e4+1;
const int N = 1e5+1;

vi edges[M];

vi adj[N];

int indegree[N];

int n, m;

bool p(int mid){
	for(int i = 1; i <= n; i++) indegree[i] = 0;
	for(int i = 1; i <= n; i++) adj[i].clear();
	for(int o = 1; o <= mid; o++){
		for(int j = 1; j < edges[o].size(); j++){
			adj[edges[o][j-1]].pb(edges[o][j]);
			indegree[edges[o][j]]++;
		}
	}	
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0) q.push(i);
	}
	int vis = 0;
	while(!q.empty()){
		int ft = q.front(); q.pop(); vis++;
		for(auto a: adj[ft]){
			indegree[a]--;
			if(indegree[a] == 0) q.push(a);
		}
	}
	if(vis != n) return false;
	return true;
}

void least(int mid){
	for(int i = 1; i <= n; i++) indegree[i] = 0;
	for(int i = 1; i <= n; i++) adj[i].clear();
	for(int o = 1; o <= mid; o++){
		for(int j = 1; j < edges[o].size(); j++){
			adj[edges[o][j-1]].pb(edges[o][j]);
			indegree[edges[o][j]]++;
		}
	}	
	pq q;
	for(int i = 1; i <= n; i++){
		if(indegree[i] == 0) q.push(i);
	}
	vi ans;
	while(!q.empty()){
		int ft = q.top(); q.pop();
		ans.pb(ft);
		for(auto a: adj[ft]){
			indegree[a]--;
			if(indegree[a] == 0) q.push(a);
		}
	}
	for(int i = 0; i < ans.size()-1; i++) cout << ans[i] << " ";
	cout << ans[ans.size()-1] << endl;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("milkorder.in","r",stdin); freopen("milkorder.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x; cin >> x;
		for(int j = 0; j < x; j++){
			int nx; cin >> nx;
			edges[i].pb(nx);
		}
	}

	int lo = 1, hi = m;
	while(lo < hi){
		int mid = lo + (hi-lo+1)/2;
		if(p(mid) == false){
			hi = mid-1;
		}
		else{
			lo = mid;
		}
	}
	if(p(lo) == false){
		cout << "all false" << endl;
	}
	else least(lo);

}
