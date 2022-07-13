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
int n, m;
const int M = 510;
const int N = 10010;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> m;
	vl d(n);
	rep(i, n){
		cin >> d[i]; 
	}
	vector<vl> dp(m+1, vl(m+n+10));
	for(int minute = 1; minute <= n; minute++){
		dp[0][minute] = max(dp[0][minute], dp[0][minute-1]);
		for(int i = 1; i <= m; i++){
				if(i <= m){
					dp[i][minute] = max(dp[i][minute], dp[i-1][minute-1]+d[minute-1]);
					dp[0][minute+i-1] = max(dp[0][minute+i-1], dp[i][minute-1]);
				}
		}
	}

	ll res = -1e18;
	for(int minute = 0; minute <= n; minute++){
		res = max(res, dp[0][minute]); 
	}
	out(res);

}