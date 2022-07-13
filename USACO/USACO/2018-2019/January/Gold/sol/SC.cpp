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

const int mx = 10001;

ll N, M, T;

vector<pi> edges[mx];
vi back[mx], cow;
ll counter[mx], b[mx], W[mx];


int dfs(int c){
	if(b[c] == 1) return 0;
	b[c] = 1; int res = cow[c-1];
	for(auto a: back[c]) res += dfs(a);
	
	counter[c] = res;
	return res;
}
void Dijk(){
	set<vector<vi>> dist;
	set<int> found;

	vector<vi> base = {{0},{0},{1}}; dist.insert(base);
	//cout << *dist.begin()[0] << " " *dist.begin()[1] << endl;

	for(int i = 0; i < mx; i++) W[i] = 1e18;
	W[1] = 0;

	while(!dist.empty()){
		vector<vi> nxt = *dist.begin();
		int forward = nxt[2][0];
		dist.erase(dist.begin());
		if(found.find(forward) != found.end()) continue;
		found.insert(forward);
		int org = nxt[1].front(); //front of list of nodes
		back[org].pb(forward);
		vi additional; additional.pb(forward);
		for(auto a: nxt[1]) additional.pb(a);
		for(auto a: edges[forward]){
			if(W[a.f] >= W[forward] + a.s){
				W[a.f] = W[forward] + a.s;
				vector<vi> v = {{(int) W[a.f]}, 
				additional, {a.f}};
				dist.insert(v);
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("shortcut.in","r",stdin); //freopen("shortcut.out","w",stdout);	
	//before you start coding, think it through
	cin >> N >> M >> T;
	for(int i = 0; i < N; i++){
		int x; cin >> x; cow.pb(x);
	}
	for(int i = 0; i < M; i++){
		int x, y, z; cin >> x >> y >> z;
		edges[x].pb({y,z});
		edges[y].pb({x,z});
	}
	Dijk();
	for(int i = 1; i <= N; i++) dfs(i);
	ll fin = 0;
	for(int i = 1; i <= N; i++){
		fin = max(fin, (W[i]*counter[i]) - (counter[i] * T));
	}
	cout << fin << endl;
}
