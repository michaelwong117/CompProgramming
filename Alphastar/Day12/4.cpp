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

//keep track of important variables in dp
//what something begins with, what something ends with, the end state of a variable
//getting proper ending solutions
//e.g. to get all solutions that end with zero total weight, dp[0][...]
//if you only need to track certain states, you can use mod and reset the dp array with impossible value


int n, c, h[100001], dp[2][101];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> c;

	for(int i = 1; i <= n; i++) cin >> h[i];

	for(int i = 0; i < 2; i++){
		for(int hi = 0; hi <= 100; hi++) dp[i][hi] = 1e9;
	}
	for(int i = h[1]; i <= 100; i++){
		for(int j = h[2]; j <= 100; j++){
			dp[1][j] = min(dp[1][j], (i - h[1]) * (i - h[1]) + (j - h[2]) * (j - h[2]) + c * abs(i - j));
		}
	}
	for(int i = 2; i < n; i++){
		for(int h1 = h[i+1]; h1 <= 100; h1++){
			for(int h2 = h[i]; h2 <= 100; h2++){
				dp[i % 2][h1] = min(dp[i % 2][h1], dp[(i % 2 == 0) ? 1 : 0][h2] + abs(h2-h1) * c + (h1 - h[i+1]) * (h1 - h[i+1]));
			}
		}
		for(int h2 = h[i]; h2 <= 100; h2++){
			dp[(i % 2 == 0) ? 1 : 0][h2] = 1e9;
		}
	}
	int res = 1e9;
	for(int i = h[n]; i <= 100; i++){
		res = min(res, dp[(n % 2 == 0) ? 1 : 0][i]);
	}
	cout << res << endl;

		



}