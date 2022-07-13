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
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

ll n, k, team[100001], dp[100001][101], mx[100001][101];

ll days;

ll solve(int prev, int cur, int spent){ 
	if(cur > n) return 0;
	// cout << "score " << mx[prev][cur-prev] << endl;
	// cout << prev << " " << cur << " " << spent << endl;
	// cout << endl;


	if(dp[prev][cur-prev] != -1) return dp[prev][cur-prev];

	//1,4 is 4 elements, 1,2,3,4
	if(spent == days){
		dp[prev][cur-prev] = mx[prev][cur-prev];
		return dp[prev][cur-prev];
	}
	if(cur - prev + 1 == k){
		dp[prev][cur-prev] = mx[prev][cur-prev] + solve(cur+1, cur+1, spent+1);
		return dp[prev][cur-prev];
	}
	else{
		dp[prev][cur-prev] = max(mx[prev][cur-prev] + solve(cur+1, cur+1, spent+1), solve(prev, cur+1, spent));
	}


	return dp[prev][cur-prev];


}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); 	
	//before you start coding, think it through
	cin >> n >> k;
	if(n % k == 0) days = n/k;
	else days = n / k + 1;
	for(int i = 1; i <= n; i++){
		cin >> team[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < k; j++){
			if(j > 0) mx[i][j] = max(team[i+j], mx[i][j-1]);
			else mx[i][j] = team[i+j];
			dp[i][j] = -1;
		}
	}
	ll res = solve(1, 1, 1);
	// for(int j = 0; j <= k; j++){
	// 	res = max(res, solve(1, 1+j));
	// }
	cout << res << endl;
	//k = 4

	// dp[1][2] -> dp[1][3]

	// dp[1][4] + max(best[5][5], best[5][6], best[5][7], best[5][8])

	// dp[1][3] + max(best[5][0], best[5][1], best[5][2], best[5][3])



}
