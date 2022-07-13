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
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int mx = 500;
int s, n, dp[mx+1];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("filename.in","r",stdin); //freopen("filename.out","w",stdout);	
	while(1){
		cin >> s >> n; if(s == 0 && n == 0) return 0;
		rep(i, s) dp[i+1]=-1e9;
		rep(i, n){
			int sz, val; cin >> sz >> val;
			for(int w = s-sz; w >= 0; w--){
				if(dp[w] != -1e9) dp[w+sz] = max(dp[w+sz],dp[w]+val);
			}
		}
		pi res = {1e9,-1e9};
		rep(i, s+1) if(res.s < dp[i]) res = {i, dp[i]};
		cout << res.f << " " << res.s << endl;
	}
	
}