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
const int mx = 1e5+1;
int t, n, a[100], dp[mx];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("filename.in","r",stdin); //freopen("filename.out","w",stdout);	
	cin >> t;
	rep(i, t){
		cin >> n;
		int sum = 0; dp[0] = 1;
		rep(i, n){
			cin >> a[i]; sum += a[i];
		}
		for(int i = 0; i < n; i++){
			for(int w = sum-a[i]; w >= 0; w--){
				if(dp[w]) dp[w+a[i]]=1;
			}
		}
		ll res = 0;
		for(int i = 1; i <= sum; i++) if(dp[i]) res += (ll) i;
		out(res);
		memset(dp,0,sizeof dp);
	}
}