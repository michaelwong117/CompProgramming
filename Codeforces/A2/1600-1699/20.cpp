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

vpi row[1001], col[1001], drifts;
vi groups (101, -1);

void dfs(int x, int y, int name){
	for(int j = 0; j < row[x].size(); j++){
		if(groups[row[x][j].s] == -1){
			groups[row[x][j].s] = name;
			dfs(x, row[x][j].f, name);
		}	
	}
	for(int j = 0; j < col[y].size(); j++){
		if(groups[col[y][j].s] == -1){
			groups[col[y][j].s] = name;
			dfs(col[y][j].f, y, name);
		}	
	}
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n; cin >> n;
	rep(i, n){
		int x, y; cin >> x >> y;
		row[x].pb({y, i});
		col[y].pb({x, i});
		drifts.pb({x, y});
	}
	int c = 0;
	for(int i = 0; i < drifts.size(); i++){
		if(groups[i] == -1){
			c++;
			int x = drifts[i].f, y = drifts[i].s;
			groups[i] = c;
			dfs(x, y, c); 
			
		}
	}
	out(c-1);
}