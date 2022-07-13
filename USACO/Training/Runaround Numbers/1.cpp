/*
ID: michaelwong11
PROG: runround
LANG: C++14     
*/
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

bool unique(ll num){
	vector<bool> vis (10);
	while(num > 0){
		if(vis[num%10]) return false;
		vis[num%10] = 1;
		num /= 10;
	}
	return true;
}

bool isrr(ll num){
	vi dig;
	while(num > 0){
		dig.pb(num%10); num /= 10;
	}
	reverse(all(dig));
	int sz = dig.size();
	vector<bool> seen(sz);

	//work
	int pos = 0; seen[0] = 1;
	// cout << pos << " " << dig[pos] << endl;
	while(1){
		pos = (pos+dig[pos])%sz;
		// cout << pos << " " << dig[pos] << endl;
		if(dig[pos] == dig[0]){
			for(int i = 0; i < sz; i++){
				if(seen[i] == 0) return false;
			}
			return true;
		} 
		else if(seen[pos]) return false;
		seen[pos] = 1;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("runround.in","r",stdin); freopen("runround.out","w",stdout);
	ll m; cin >> m;
	for(ll i = m+1; ; i++){
		if(!unique(i)) continue;
		if(isrr(i)){
			cout << i << endl;
			return 0;
		}
	}





}