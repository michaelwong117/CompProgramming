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
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;\

int a[5*10000+1];
vi f[101];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through

	int n; cin >> n;
	int sum = 0, mn = 1e9, mnidx;
	for(int i = 0; i < n; i++){
		cin >> a[i]; sum += a[i];
		if(mn > a[i]){
			mn = a[i];
			mnidx = i;
		}
	}
	int res = sum;
	if(n == 1){
		cout << res << endl;
		return 0;
	}

	// cout << sum << " " << mn << " " << mnidx << endl;
	for(int i = 1; i <= 100; i++){
		for(int j = ((int) sqrt(i)) + 1; j >= 1; j--){
			if(j > i) continue;
			if(i % j == 0){
				f[i].pb(j);
			}
		}
		// cout << i <<  endl;
		// for(auto a: f[i]){
		// 	cout << a << " ";
		// }
		// cout << endl << endl;
	}
	int best = 0;
	for(int i = 0; i < n; i++){
		if(i == mnidx) continue;
		for(auto fac: f[a[i]]){
			// cout << a[i] << " " << fac << endl;
			best = min(best, mn * fac - mn - (a[i] - a[i] / fac));
		}
	}
	cout << min(sum, sum + best) << endl;
}

