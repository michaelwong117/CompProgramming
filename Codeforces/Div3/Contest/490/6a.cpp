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

const int mx = 100020;

int c[mx], fav[mx];


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n, k; cin >> n >> k;
	vector<vi> dp(110, vi(n*k+20));
	vi joy(k+1);

	rep(i, k*n){
		int x; cin >> x;
		c[x]++;
	}

	rep(i, n){
		int x; cin >> x;
		fav[x]++;
	}
	
	rep(i, k) cin >> joy[i+1];

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= n*k; j++){
			for(int x = 1; x <= k; x++){
				dp[i+1][j+x] = max(dp[i+1][j+x], dp[i][j]+joy[x]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < mx; i++){
		if(fav[i] != 0) ans += dp[fav[i]][c[i]];
	}
	cout << ans << endl;





	

}