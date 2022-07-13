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

const int mx = 11001;

ll N, M, T;

vector<pi> edge[mx];
vi back[mx], cow;
ll counter[mx], b[mx], W[mx];

struct Edge{

	int weight;

	vi list;

	int next;

	bool operator<(Edge other) const {
		if(weight != other.weight){
			return weight < other.weight;
		}
		else{
			return list < other.list;
		}
	}

};


int dfs(int c){
	if(b[c] == 1) return -1;
	b[c] = 1; int res = cow[c];
	for(auto a: back[c]){
		int nx = dfs(a);
		if(nx != -1) res += nx;
	}
	
	counter[c] = res;
	return res;
}
void Dijk(){
	//use set so you don't have to use
	//pq syntax for operators
	set<Edge> dist; 

	Edge base = {0,{0},1}; dist.insert(base);
	//cout << *dist.begin()[0] << " " *dist.begin()[1] << endl;

	for(int i = 0; i < mx; i++) W[i] = 1e18;
	W[1] = 0;

	set<int> s;
	while(!dist.empty()){
		Edge nxt = *dist.begin(); dist.erase(dist.begin());

		int forward = nxt.next, cur;


		if(s.find(forward) != s.end()) continue;
		s.insert(forward);

		int org = nxt.list.front(); //front of list of nodes
		back[org].pb(forward);
		vi addit; addit.pb(forward);


		for(auto a: nxt.list) addit.pb(a);

		for(auto a: edge[forward]){
			if(W[a.f] >= W[forward] + a.s){
				// cout << W[a.f] << " " << W[forward] << " " << a.s << endl;
				// for(auto c: addit){
				// 	cout << c << " ";
				// }
				// cout << endl;
				W[a.f] = W[forward] + a.s;
				Edge v = {(int) W[a.f], 
				addit, a.f};
				// cout << "jump " << a.f << endl;
				dist.insert(v);
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("shortcut.in","r",stdin); freopen("shortcut.out","w",stdout);	
	//before you start coding, think it through
	cow.pb(0);
	cin >> N >> M >> T;
	for(int i = 1; i <= N; i++){
		int x; cin >> x; cow.pb(x);
	}
	for(int i = 0; i < M; i++){
		int x, y, z; cin >> x >> y >> z;
		edge[x].pb({y,z});
		edge[y].pb({x,z});
	}
	Dijk();
	for(int i = 0; i <= N; i++) dfs(i);

	ll fin = 0;
	for(int i = 1; i <= N; i++){
		fin = max(fin, (W[i] * counter[i]) - (counter[i] * T));
	}
	cout << fin << endl;
}
