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
vi v;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("filename.out","w",stdout);	
	int n, k;
	cin >> n >> k; 
	rep(i, n){
		int x; cin >> x;
		v.pb(x);
	}
	sort(all(v), greater<int>());
	if(n == k){
		cout << 1000000000 << endl;
	}
	else if(k == 0){
		if(v[n-1] == 1) cout << -1 << endl;
		else cout << 1 << endl;
	}
	else if(v[n-k-1] == v[n-k]){
		cout << -1 << endl;
	}
	else{
		cout << v[n-k] << endl;
	}
}