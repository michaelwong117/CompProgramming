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

int grid[250][250];
vi sz(250*250+1), nametonum(250*250+1);
vector<vi> comp(250, vi(250));
set<pi> borders[250*250+1];

int dx[]={ 0, 0,+1,-1};
int dy[]={+1,-1, 0, 0};
int n;

bool valid(int x, int y, int a, int b, int name){
	if(x >= n || y >= n || x < 0 || y < 0) return false;
	if(a != grid[x][y] && b == -1){
		borders[name].insert({x,y});
		return false;
	}
	if(a != grid[x][y] && b != grid[x][y]) return false;
	assert(a == grid[x][y] || b == grid[x][y]);
	//hasn't been named
	if(comp[x][y] != 0) return false;
	else comp[x][y] = name;
	return true;
}

void bfs1(int x, int y, int a, int b, int name){
	queue<pi> q;
	q.push({x,y});
	int SZ = 1;
	while(!q.empty()){
		pi ft = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			if(valid(ft.f+dx[i], ft.s+dy[i], a, b, name)){
				SZ++;
				q.push({ft.f+dx[i],ft.s+dy[i]});
			}
		}
	}
	sz[name] = SZ;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("multimoo.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n;
	rep(i, n){
		rep(j, n){
			cin >> grid[i][j];
		}
	}
	int c = 0;
	rep(i, n){
		rep(j, n){
			if(comp[i][j] == 0){
				c++;	
				comp[i][j] = c;
				nametonum[c] = grid[i][j];
				bfs1(i, j, grid[i][j], -1, c);
			}
		}
	}
	int mx = -1;
	for(int i = 1; i <= c; i++){
		mx = max(mx, sz[i]);
	}
	out(mx);
	int mxi = -1;
	for(int i = 1; i <= c; i++){
		cout << "THIS IS GROUP " << i << endl;
		cout << "number " << nametonum[i] << " size " << sz[i] << endl;
		cout << "BORDERS:" << endl;
		for(auto j: borders[i]){
			int x = j.f, y = j.s;
			if(!s[i][comp[x][y]]){
				
			}
			cout << "bnumber " << grid[x][y] <<" coords at " << x << " " << y << endl;

		}
		// for(int j = 0; j < borders[name].size(); j++){
		// 	int x = borders[cur][j].f, y = borders[cur][j].s;
		// 	int nex = comp[x][y];
		// 	bfs(i, nex);
		// }
		
		
		
	}

}