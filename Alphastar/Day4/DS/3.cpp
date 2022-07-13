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

//AC

int N, a, b, h;

bool seen[40001];
int H[40001];

vpi pts;

multiset<pi> s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a >> b >> h;
		pts.pb({a, i}); pts.pb({b, i}); H[i] = h;
	}
	sort(all(pts));
	ll totalA = 0;
	for(int i = 0; i < pts.size()-1; i++){
		int st = pts[i].f, id = pts[i].s, stH = H[id];
		int end = pts[i+1].f;
		if(!seen[id]){ //new building
			s.insert({stH, id}); seen[id] = 1;
		} 
		else{
			s.erase({stH, id});
		}
		if(s.empty()) continue; //if there are no buildings from st to end
		int mxH = (*s.rbegin()).f;
		totalA += (end-st) * (ll) mxH;
	}
	cout << totalA << endl;


}
