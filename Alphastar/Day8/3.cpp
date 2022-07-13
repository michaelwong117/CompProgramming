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


vi market(6);


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	

	int n, m, k; cin >> n >> m >> k;

	for(int i = 1; i <= k; i++){
		cin >> market[i];
	}

	for(int i = 0; i < m; i++){
		int a, b, w; cin >> a >> b >> w;
		edges.pb({w, a, b});
	}

	int a[5];
	iota(a, a+k, 1);
	ll res = 1e18;
	do {
		ll tot = 0;
		for(int i = 0; i < k-1; i++){
			tot += (ll) dijkstra(market[a[i]], market[a[i+1]]);
		}
		ll add = 1e18;
		for(int i = 1; i <= n; i++){
			for(int i = 0; i < k; i++){
				add = min(add, dijkstra(i, market[a[i]]));
			}
		}
		res = min(res, tot+add);
	} while(next_permutation(a, a+k));
	out(res);


}