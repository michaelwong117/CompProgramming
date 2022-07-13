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
#define endl '\n'
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int mx = 1e5;

int n;
ll dp[mx], cst[10], rt[10]; 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("filename.in","r",stdin); //freopen("filename.out","w",stdout);
	cin >> n;
	rep(i, n){
		ll cap, y, d; cin >> cap >> y >> d;
		rep(i, d){
			cin >> cst[i] >> rt[i]; cst[i] /= 1000;
		}
		rep(i, (cap/1000)+1) dp[i+1] = -1e9; 
		rep(i, y){
			ll tmp = cap; cap /= 1000;
			rep(i, d){
				for(int w = 0; w <= cap-cst[i]; w++){
					if(dp[w] != -1e9) dp[w+cst[i]] = max(dp[w+cst[i]], dp[w]+rt[i]);
				}
			}
			ll res = 0;
			rep(i, cap+1) res = max(res, dp[i]);
			tmp += res; cap = tmp;
		}
		cout << cap << endl;
		memset(dp,0,sizeof dp);

	}


}