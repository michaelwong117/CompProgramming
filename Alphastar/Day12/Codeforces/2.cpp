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
	int n; cin >> n;
	vector<pl> bea(n);
	rep(i, n) cin >> bea[i].f >> bea[i].s;
	sort(all(bea));
	vl dp(1000001);
	ll mx = -1e18;
	dp[bea[0].f] = 1; int k = 1; 
	for(int i = 1; i <= 1000000; i++){
		if(k >= bea.size()) continue;
		if(bea[k].f != i){
			dp[i] = max(dp[i], dp[i-1]); 
			continue;
		}
		//cout << i << " " << bea[k].s << endl;
		if(i - bea[k].s > 0){
			dp[i] = max(dp[i], dp[i - bea[k].s - 1] + 1);
			//cout << dp[i - bea[k].s - 1] << endl;
		}
		else{
			dp[i] = max(dp[i], 1ll);
		}
		mx = max(mx, dp[i]);
		k++;

	}
	//cout << mx << " " << dp[bea[n-1].f] << endl;
	cout << n - max(mx, dp[bea[n-1].f]) << endl;
}