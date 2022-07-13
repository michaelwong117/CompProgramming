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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n, k; cin >> n >> k; vpi v(n);
	rep(i, n){
		cin >> v[i].f;
		v[i].s = i;
	}
	sort(all(v),greater<pi>());
	ll total = 0;
	vi final;
	rep(i, k){
		total += v[i].f;
		final.pb(v[i].s);
	}
	sort(all(final));
	out(total);
	if(final.size() == 1){
		cout << n << endl;
		return 0;
	}
	rep(i, final.size()){
		if(i == 0){
			cout << final[0]+1 << " ";
		}
		else if(i == final.size()-1){
			cout << n-final[i-1]-1 << endl;
		}
		else cout << final[i]-final[i-1] << " ";
	}
}