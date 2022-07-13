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

unordered_map<int, int> m;

//THIS IS NOT THE FINAL VERSION, SEE 6a
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n, K; cin >> n >> K;
	vi c(100000), card(K*n), fav(n), joy(K+1);
	rep(i, K*n){
		cin >> card[i];
		c[card[i]]++;
	}
	rep(i, n){
		cin >> fav[i];
		if(m.find(fav[i]) == m.end()) m[fav[i]] = 0;
		else m[fav[i]]++;

	}
	rep(i, K) cin >> joy[i+1];
	ll tjoy = 0;
	for(auto a: m){
		//a.f is what the favorite card is
		//a.s is how many players have that favorite

		//if more than one player has the same favorite
		if(a.s > 1){
			//c[a.f] is how many favorites are left
			vector<vector<vi>> dp (c[a.f]+1, vector<vi>(a.s, vi(K+1, -1e9)));
			//int dp[c[a.f]+1][a.s+1][K+1];

			rep(j, a.s+1) dp[c[a.f]][j][K] = 0;

			for(int i = c[a.f]; i >= 1; i--){
				for(int j = 0; j < a.s; j++){
					for(int k = K; k >= 1; k--){
						dp[i-1][j][k-1] = max(dp[i-1][j][k-1], dp[i][j][k]+joy[K-k-1]);
					}
				}
			}

			
			//dp[i][j][k] is the joy value
			//maximize, test all players w/ shared favorite
			//i is how many of the fav card we have left
			//j is the current player we're on
			//k is how many cards the player already has left to get
			
		}
		else{
			tjoy += joy[min(K,c[a.f])-1];
		}

	}

	

}