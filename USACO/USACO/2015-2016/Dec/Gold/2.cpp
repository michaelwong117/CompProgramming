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

const int mx = 5*1e6+5;

int t, f[2];
vector<vector<bool>> dp(2, vector<bool>(mx));

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("feast.in","r",stdin); freopen("feast.out","w",stdout);	
	cin >> t >> f[0] >> f[1];
	dp[1][0] = 1; dp[0][0] = 1;
	//run it twice so after you have all dp[1][(full+f[i]/2)] set, you can
	//run standard knapsack again
	for(int c = 0; c < 2; c++){	
		//iterating through fruit
		for(int i = 0; i < 2; i++){
			//iterating through possible weights
			for(int full = 0; full <= t-f[i]; full++){
				if(dp[0][full]){ 
					// cout << "b4 " << full << endl;
					dp[0][full+f[i]]=1; 
					dp[1][(full+f[i])/2]=1; 
				}
				if(dp[1][full]){
					// cout << "after " << full << endl;
					dp[1][full+f[i]]=1;
				}
			}
		}
	}
	int mx = -1e9;
	for(int o = 0; o < 2; o++){
		for(int full = t; full >= 0; full--){
			if(dp[o][full]){
				mx = max(mx, full); break;
			}
		}
	}
	cout << mx << endl;


}