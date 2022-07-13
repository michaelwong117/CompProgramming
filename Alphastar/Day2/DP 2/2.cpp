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
	int h, n; cin >> h >> n;
	vi w(n), dp(h+1, -1e9);
	rep(i, n){
		cin >> w[i]; 
	}
	//dp[i] is the maximum kg of hay given limit i weight
	dp[0] = 0;
	for(int j = 0; j < n; j++){
		for(int i = h-w[j]; i >= 0; i--){
			if(dp[i] != -1e9) dp[i+w[j]] = max(dp[i+w[j]], dp[i]+w[j]);
		}
	}
	int res = -1e9;
	rep(i, h+1) res = max(res, dp[i]);
	out(res);
}