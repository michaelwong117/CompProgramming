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
#define out(x) cout << x << endl;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int mx = 2*1e5+1;

int n, a[mx];
Tree<pi> T;
vpi query[mx];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("filename.in","r",stdin); //freopen("filename.out","w",stdout);	
	cin >> n;
	ll ans = 0;
	rep(i,n) cin >> a[i+1];
	for(int i = 1; i <= n; i++){
		if(i < min(n,a[i])){
			query[i].pb({i,-1});
			query[min(a[i],n)].pb({i,1});
		}
	}
	for(int i = 1; i <= n; i++){
		T.insert({a[i],i});
		for(auto a: query[i]) ans += a.s*((int)T.size()-(int)T.order_of_key({a.f,-MOD}));
	}
	cout << ans << endl;


}