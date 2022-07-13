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
const int N = 1e3+1;

ll pairs[N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	ll n; cin >> n;
	ll m; cin >> m;
	ll res = 0, div = n/m, rem = n - div * m;

	for(ll i = 1; i <= m; i++){
		ll tot = (i * i) % m;
		// cout << i << " " << tot << " " << rem << endl;
		//1 and 6 if m is five, make sure to add the extra
		//div is for if 1 and 6 and 11, div = 2 + extra for 11
		if(i <= rem){
			pairs[tot] += div + 1;
		}
		else{
			pairs[tot] += div;
		}

	}
	//for(int i = 0; i < m; i++) cout << i << " " << pairs[i] << endl;
	//zero pairs with zero
	res += pairs[0] * pairs[0];
	for(ll i = 1; i < m; i++){
		//mods need to add up to m to be divisible
		res += pairs[i] * pairs[m-i];
	}
	cout << res << endl;
}
